mkdir build\testlang_debug
pushd build\testlang_debug

cmake -S ..\..\testlang -DCMAKE_BUILD_TYPE=Debug -DINSTALL_PATH=%1
msbuild -p:Configuration=Debug derammo_testlang.sln
popd

mkdir build\testlang
pushd build\testlang
cmake -S ..\..\testlang -DCMAKE_BUILD_TYPE=Debug -DINSTALL_PATH=%1
msbuild -p:Configuration=Release derammo_testlang.sln
popd
