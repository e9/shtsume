source "/home/e9/emscripten-core/emsdk/emsdk_env.sh"
emcc source/wasm.c source/shtsume.c source/ntbase.c source/nbase.c source/base.c  source/ncheck.c source/nusi.c source/usi.c source/nsearchinf.c  source/bitboard.c source/global.c source/nevasion.c  source/ndtools.c source/dtools.c \
-s ALLOW_MEMORY_GROWTH \
-s MODULARIZE=1 \
-s ENVIRONMENT='worker' \
-s EXPORTED_FUNCTIONS="['_solve']" \
-s EXPORTED_RUNTIME_METHODS="['allocateUTF8', 'UTF8ToString']" \
-o solver.js
