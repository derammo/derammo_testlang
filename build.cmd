mkdir build

mkdir build\godot-cpp_debug
pushd build\godot-cpp_debug
cmake -S ..\..\godot-cpp -DCMAKE_BUILD_TYPE=Debug
msbuild -p:Configuration=Debug godot-cpp.sln
popd

mkdir build\testlang_debug
pushd build\testlang_debug

cmake -S ..\..\testlang -DCMAKE_BUILD_TYPE=Debug
msbuild -p:Configuration=Debug derammo_testlang.sln
popd

mkdir build\godot-cpp
pushd build\godot-cpp
cmake -S ..\..\godot-cpp -DCMAKE_BUILD_TYPE=Release
msbuild -p:Configuration=Release godot-cpp.sln
popd


mkdir build\testlang
pushd build\testlang
cmake -S ..\..\testlang -DCMAKE_BUILD_TYPE=Debug
msbuild -p:Configuration=Release derammo_testlang.sln
popd
