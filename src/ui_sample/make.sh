#!/bin/bash

main_dir="/home/axr/prog/projects/OOP/src/ui_sample"
build_dir="${main_dir}/build"
exec_dir="${main_dir}/executables"

#mkdir ${build_dir}
cd ${build_dir}

cmake ../
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ${main_dir}
make

mv ${build_dir}/app ${main_dir}/app

