#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>
#include <unistd.h>
#include "shogi.h"
#include "usi.h"
#include "shtsume.h"
#include "ndtools.h"

bool g_commandline = true;

char *solve(char *g_sfen_pos_str)
{
    // g_sfen_pos_str = "3sks3/9/4+P4/9/9/B8/9/9/9 b S2rb4gs4n4l17p 1";

    // 基本ライブラリの初期化処理
    create_seed();   // zkey
    init_distance(); // g_distance
    init_bpos();     // bitboard
    init_effect();   // effect
    srand((unsigned)time(NULL));

    // 詰将棋条件の表示
    ssdata_t ssdata;
    sfen_to_ssdata(g_sfen_pos_str, &ssdata);
    initialize_sdata(&g_sdata, &ssdata);

    // 局面の合法性check
    int err = is_sdata_illegal(&g_sdata);
    if (err)
    {
        switch (err)
        {
        case CHECKED:
            return "CHECKED";
        case NIFU:
            return "NIFU";
        case ILL_POS:
            return "ILL_POS";
        }
    }

    // tbaseの作成
    uint64_t size = g_usi_hash * MCARDS_PER_MBYTE - 1;
    g_tbase = create_tbase(size);
    g_mtt = create_mtt(MTT_SIZE);

    g_time_limit = TM_INFINATE;
    tdata_t tdata;
    bn_search(&g_sdata, &tdata, g_tbase);

    // char str[SZ_USIBUFFER];
    char *str = (char *)malloc(SZ_USIBUFFER + 1);

    if (!tdata.pn)
    {
        if (g_error)
        {
            return "ERROR";
        }

        int num = 0;
        move_t mv;
        for (int i = 0; i < TSUME_MAX_DEPTH; i++)
        {
            mv = g_tsearchinf.mvinf[i].move;
            if (MV_TORYO(mv))
                break;
            num += move_to_sfen(str + num, mv);
            num += sprintf(str + num, " ");
        }
    }

    initialize_tbase(g_tbase);
    init_mtt(g_mtt);
    mlist_free_stack();
    mvlist_free_stack();

    return str;
}
