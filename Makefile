
FLAGS=-xc -Wall -Wextra -Werror -Wpedantic -pedantic -pedantic-errors -std=c89 -fcolor-diagnostics
SRC_FILES=$(wildcard src/*.c) $(wildcard lib/file/*.c) $(wildcard lib/device/*.c)


local: clean build run
clean:
	@echo "Cleaning..."
	@rm -rf bin

build: clean
	@echo "Compiling..."
	@mkdir bin
	@clang ${FLAGS} ${SRC_FILES} -o bin/monitor

run:
	@echo "Running..."
	@chmod +x bin/monitor
	@cd bin && ./monitor


remote: clean_remote build_remote run_remote
clean_remote:
	@echo "Cleaning... (Remote)"
	@docker rm -f monitor_instance

build_remote:
	@echo "Building... (Remote)"
	@docker build -t monitor:0.1 .
	# --progress=plain .

run_remote: clean_remote
	@echo "Running...  (Remote)"
	@docker run -i --name monitor_instance monitor:0.1

