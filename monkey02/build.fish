#!/usr/bin/fish

if test -d build
    rm -rf build
end

mkdir build
cd build

cmake -G Ninja ..
ninja -j31
