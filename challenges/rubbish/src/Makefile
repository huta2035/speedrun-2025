CC=gcc
DEPS=
OBJ=challenge.o
BIN=rubbish
CFLAGS=
LDFLAGS=-no-pie

BIN_PATH := bin
OBJ_PATH := obj

.PHONY: default
default: flag all

.PHONY: flag
flag: 
	python3 generate.py

.PHONY: all
all: makedir $(BIN_PATH)/$(BIN)

.PHONY: clean
clean:
	rm -rf $(OBJ_PATH) $(BIN_PATH)
	rm -f flag.h

.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: %.c $(DEPS)
	echo $@ $<
	$(CC) $(CFLAGS) -c -o $@ $<

$(BIN_PATH)/$(BIN): $(addprefix $(OBJ_PATH)/,$(OBJ))
	$(CC) -o $@ $^ $(LDFLAGS)
