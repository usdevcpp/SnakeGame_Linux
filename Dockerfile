FROM alpine:latest
RUN apk add build-base ncurses-dev openssh
RUN mkdir /home/Snake
COPY . /home/Snake
