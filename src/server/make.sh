#!/bin/bash

main_dir="/home/axr/prog/projects/OOP/src/server_cpp"
build_dir="${main_dir}/build"

mkdir ${build_dir}
cd ${build_dir}

cmake ../
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ${main_dir}
make

mv ${build_dir}/server ${main_dir}/server
mv ${build_dir}/compile_commands.json ${main_dir}/compile_commands.json 

