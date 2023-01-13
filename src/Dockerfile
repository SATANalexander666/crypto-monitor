FROM ubuntu:18.04

WORKDIR /software_build

RUN apt-get update && \
    apt-get install -y && \
    cmake && \
    libzmq3-dev && \
    python3 && \
    qt && \
    pip 

RUN pip install zmq requests pyinstaller chardet

WORKDIR /app

ADD /client_with_ui /app/code

WORKDIR /app/build

RUN cmake ../code && \
    cmake --build . && \
    make

WORKDIR /app/code

RUN pyinstaller --onefile pysrc/Updater.py

WORKDIR /app/executables

COPY /app/code/dist/Updater ./
COPY /app/build/app ./
