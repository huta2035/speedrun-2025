SRC_PATH := src

.PHONY: all CHALLENGE docker
all: CHALLENGE docker 

RAND_FLAG=$(shell openssl rand -hex 32)

CHALLENGE:
	@mkdir -p dist
	@cp docker.template/* dist/
	@cp bytecode.txt dist/

docker: CHALLENGE
	@mkdir -p docker
	@cp -r docker.template/* docker/
	@cp -r src/ docker/
	@sed -i 's/r4nd0m_f14g_f4r_d3m0/$(RAND_FLAG)/g' docker/src/index.php

clean:
	rm -rf dist/
	rm -rf docker/
