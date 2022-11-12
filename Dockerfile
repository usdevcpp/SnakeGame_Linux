FROM alpine:latest
<<<<<<< HEAD
RUN apk add build-base ncurses-dev openssh git
=======
RUN apk add build-base ncurses-dev openssh gdb
>>>>>>> done
RUN mkdir /home/Snake
COPY . /home/Snake
