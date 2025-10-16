CC=gcc
DEPS=
OBJ=challenge.o
BIN=fast_encryptor
CFLAGS=
LDFLAGS=-s

BIN_PATH := bin
OBJ_PATH := obj

.PHONY: default
default: all flag

.PHONY: flag
flag: 
	cp flag.png flag.png.bkp
	./$(BIN_PATH)/$(BIN)
	mv flag.png.bkp flag.png

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
