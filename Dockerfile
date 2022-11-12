FROM alpine:latest
RUN apk add build-base ncurses-dev openssh gdb
RUN mkdir /home/Snake
COPY . /home/Snake
