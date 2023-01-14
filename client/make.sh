main_dir="/home/axr/prog/projects/crypto-monitor/client"
build_dir="${main_dir}/build"
exec_dir="${main_dir}/executables"

#mkdir ${build_dir}
mkdir ${build_dir}
cd ${build_dir}

cmake ../
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ${main_dir}
make

mv ${build_dir}/app ${main_dir}/app
mv ${build_dir}/compile_commands.json ${main_dir}/compile_commands.json
