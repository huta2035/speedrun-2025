CHALLENGE := easy_syscall
SRC_PATH := src

.PHONY: default
default: all

.PHONY: all
all: clean $(CHALLENGE)

$(CHALLENGE):
	@cp src/Image docker/
	@cp src/rootfs.ext4 docker/rootfs.ext4
	@cp src/run.sh docker/run.sh
	@cp src/flag docker/flag
	@mkdir -p dist
	cp solution/template.py dist/template.py
	cp -r src/qemu dist/qemu

.PHONY: clean
clean:
	@rm -f docker/Image docker/rootfs.ext4 docker/run.sh docker/flag
	rm -rf dist/
