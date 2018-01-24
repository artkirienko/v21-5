FROM alpine
RUN apk add --update build-base
COPY main.cpp /usr/src/app/
RUN cd /usr/src/app/ && g++ -o v21-5 main.cpp
CMD ["/usr/src/app/v21-5"]
