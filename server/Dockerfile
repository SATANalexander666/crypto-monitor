FROM python:latest

RUN pip install --no-cache-dir --upgrade pip && \
    pip install --no-cache-dir requests zmq pyzmq

ADD server.py /server/

WORKDIR /server/
