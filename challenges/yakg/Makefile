CHALLENGE := yakg
SRC_PATH := src
BIN_PATH := $(SRC_PATH)/bin

.PHONY: default
default: all

.PHONY: all
all: clean $(CHALLENGE)

$(CHALLENGE):
	@mkdir -p dist
	make -C src/
	cp $(BIN_PATH)/$@ dist
	cp solution/template.py dist/client.py
	cp docker/server.dist.py dist/server.py
	cp README.dist.md dist/README.md
	make -C src/ clean

.PHONY: clean
clean:
	rm -f docker/$(CHALLENGE)
	rm -rf dist
	make -C src/ clean
