# General Makefile for C projects
# to set flags use $(flag_name) and make flag_name=10

FLAGS = -xc -Wall -Wextra -Werror -Wpedantic \
	  	-pedantic -pedantic-errors -std=c89  \
	  	-fcolor-diagnostics
# \ -F/usr/include/linux


SRC_FILES=$(wildcard src/tagunstripper.c)       \
		  $(wildcard lib/*/*.c)     \
		  $(wildcard lib/*/*/*.c)   \
		  $(wildcard lib/*/*/*/*.c) \


local: clean build run
clean:
	@echo "Cleaning..."
	@rm -rf bin

build: clean
	@echo "Compiling..."
	@mkdir bin
# clang ${FLAGS} ${SRC_FILES} -o bin/monitor
	clang ${FLAGS} ${SRC_FILES} -o bin/tagunstripper

run:
# @chmod +x bin/monitor
# @cd bin && ./monitor $(iter)
	@echo "Running..."
	@chmod +x bin/tagunstripper
	@cd bin && ./tagunstripper "$(path)"


remote: clean_remote build_remote run_remote
clean_remote:
	@echo "Cleaning... (Remote)"
	@docker rm -f monitor_instance
	@docker image rm -f monitor:0.1

build_remote:
	@echo "Building... (Remote)"
	@docker build -t monitor:0.1 .
# --progress=plain

run_remote:
	@echo "Running...  (Remote)"
	@docker run -i --name monitor_instance monitor:0.1

start_remote:
	@echo "Starting container...  (Remote)"
	@docker start monitor_instance
	@docker attach monitor_instance

