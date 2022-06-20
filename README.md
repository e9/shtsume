#  shtsume

shtsumeは以下の特徴を持つ詰将棋解図プログラムです。  
・USIプロトコルに準拠しており、詰将棋エンジンとして使用する事ができます。   
・探索レベルの設定により、特定局面の詰み/不詰判定から詰将棋作品の作意推定が可能です。  
・探索LOGにより詰め手順中の玉方変化時の詰手数、駒余りの有無を確認することができます。  

[動作確認環境]  
ハード:   
Mac mini 　　 (M1 2020) メモリ16GB  
Mac Book Pro (INTEL i5) メモリ８GB  
OS:   
macOS Monterey
将棋GUI:    
将棋所Mac  

[インストール]  
プログラムの実行が可能なフォルダ（Applications等)にコピーします。

[使用方法]    
将棋所Macに詰将棋エンジンとして登録してください。  

[設定]  
メモリ　　　　128MByte - 7168MByte  
局面表に使用するメモリサイズです。難しい問題を解く場合、メモリサイズを大きく取ってください。    

レベル　　　　0 - 50  
余詰探索回数。前回の各局面証明数しきい値に１加えた値で詰み着手以外の候補手の探索を行います。  
レベルを大きく取ると迂回手順や手順前後を発見する場合があり、  
より洗練された詰手順を返すことがありますが一方時間がかかるようになります。

mt_min_pn   　3 - 10  
末端探索における最小証明数しきい値。この値を大きく取ると収束余詰を発見しやすくなります。　

out_lvkif  
チェックを入れると、詰め手順をレベル毎にuser_pathフォルダにtsumelv*.kifというファイル名で  
出力されます。（最終詰手順は除く。）

summary  
チェックを入れると詰みを発見した場合、探索情報をsearch_report(日時).logという名前で  
user_pathフォルダ内に出力されます。  

[既知の問題点]  
・マシンのメモリ容量の半分以上のメモリ設定を行うと極端に動作が遅くなります。  
　（例：８GBマシンの場合４GBまでが限度。）  
・玉方がどう応じても駒を余す手順が存在する局面の場合（実戦、不完全作など）、  
　出力手順が不定になります。  
・将棋GUIの計測時間とshtsumeの計測時間が異なってくる場合があります。    



