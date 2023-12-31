FROM alpine:3.17 AS buildkit

RUN apk add linux-headers
RUN apk add alpine-sdk
RUN apk add clang
RUN apk add make

WORKDIR /monitor

ADD ./Makefile .
ADD ./lib ./lib
ADD ./src ./src

RUN ["make", "build"]


FROM alpine:3.17

WORKDIR /monitor

COPY --from=buildkit /monitor/bin/monitor .

CMD ["./monitor"]
