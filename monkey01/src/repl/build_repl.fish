#!/usr/bin/fish

if test -d build
    printf "Deleting build dir"
    rm -rf build
end

mkdir build
cd build
cmake -G Ninja ..
ninja -j31

./lexer_repl
