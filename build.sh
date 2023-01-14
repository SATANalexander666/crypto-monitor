#!/bin/bash

#python file

server_dir="/home/axr/prog/projects/crypto-monitor/server"

pysrc_dir="${server_dir}/pysrc"

cd ${pysrc_dir}

pip install requests zmq chardet pyinstaller
pyinstaller --onefile "${pysrc_dir}/Updater.py"

#C++ files

client_dir="/home/axr/prog/projects/crypto-monitor/client"
build_dir="${project_dir}/build"

mkdir ${build_dir}
cd ${build_dir}

cmake ../
make
