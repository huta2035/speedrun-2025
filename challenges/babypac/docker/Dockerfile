FROM debian:12

RUN apt-get update && apt-get install -y socat qemu-user

RUN dpkg --add-architecture arm64 && apt-get update && apt-get install -y libc6:arm64

RUN useradd -m -s /bin/bash user
WORKDIR /home/user

COPY --chmod=755 babypac .
COPY flag.txt .

USER user

ENTRYPOINT ["socat", "TCP-LISTEN:1337,reuseaddr,fork", "EXEC:'qemu-aarch64 -L /usr/lib/ /home/user/babypac'"]
