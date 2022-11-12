FROM alpine:latest
RUN apk add build-base ncurses-dev openssh git gdb
RUN mkdir /home/Snake
COPY . /home/Snake
