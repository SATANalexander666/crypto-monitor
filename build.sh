#!/bin/bash

#python file

project_dir="/home/axr/prog/projects/crypto-monitor/src/client_with_ui"
exec_dir="${project_dir}/executables"

pysrc_dir="${project_dir}/pysrc"

cd ${pysrc_dir}

pip install requests zmq chardet pyinstaller
pyinstaller --onefile "${pysrc_dir}/Updater.py"

mv "${pysrc_dir}/dist/Updater" "${exec_dir}/Updater"

#C++ files

build_dir="${project_dir}/build"

mkdir ${build_dir}
cd ${build_dir}

cmake ../
make

mv ${build_dir}/app ${exec_dir}/app

