CHALLENGE := rubbish
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
	cp solution/template.py dist/exploit.py
	make -C src/ clean

.PHONY: clean
clean:
	rm -f docker/$(CHALLENGE)
	rm -rf dist
	make -C src/ clean
