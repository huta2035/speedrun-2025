CHALLENGE := corrupted
SRC_PATH := src
BIN_PATH := $(SRC_PATH)/bin

.PHONY: default
default: all

.PHONY: all
all: clean $(CHALLENGE)

$(CHALLENGE):
	@mkdir -p dist
	cp -r src/ dist/
	make -C src/
	cp $(BIN_PATH)/$@ docker/Dockerfile dist
	cp $(BIN_PATH)/$@ docker
	cp solution/template.py dist/exploit.py
	make -C src/ clean

.PHONY: clean
clean:
	rm -f docker/$(CHALLENGE)
	rm -rf dist
	make -C src/ clean
