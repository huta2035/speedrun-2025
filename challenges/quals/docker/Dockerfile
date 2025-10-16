FROM ubuntu:24.04

RUN apt-get update
RUN apt-get install -y qemu-system-aarch64 netcat-traditional 

RUN mkdir /app
WORKDIR /app

COPY Image /app/Image
COPY rootfs.ext4 /app/rootfs.ext4
COPY run.sh /app/run.sh
COPY flag /flag

RUN chmod 755 /app/run.sh


ENTRYPOINT ["/app/run.sh"]
