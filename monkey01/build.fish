
if test -d build
    printf "Deleting build dir"
    rm -rf build

end

mkdir build
cd build

cmake -G Ninja ..
ninja -j31

./lexer_test >output.txt 2>&1

./lexer_test
