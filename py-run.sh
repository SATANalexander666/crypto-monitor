#!/bin/bash

python3 src/server/main.py &
server_pid=$!

python3 src/client/main.py &
client_pid=$!

for i in {1..5};
do

    status=0

    if [ -n "$(ps -p ${client_pid} -o pid=)" ]; then
        status=1
    fi

    if [ -n "$(ps -p ${server_pid} -o pid=)" ]; then
        status=1
    fi

    if [[ ${status} == 1 ]]; then
        #echo "Waiting..."
        sleep 1
    else
        break
    fi

done

if [ -n "$(ps -p ${client_pid} -o pid=)" ]; then
    kill ${client_pid}
    echo "Client terminated."
fi

if [ -n "$(ps -p ${server_pid} -o pid=)" ]; then
    kill ${server_pid}
    echo "Server terminated."
fi

