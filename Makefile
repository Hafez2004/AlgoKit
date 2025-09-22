# AlgoKit Smart Makefile for C/C++

# Compiler versions
GCC_VERSION := $(shell gcc --version | head -n 1)
GXX_VERSION := $(shell g++ --version | head -n 1)

# Compilers
GCC := gcc
GXX := g++

# Detect main file (C or C++)
MAIN := $(wildcard main.c main.cpp)

# Pick compiler based on file extension
ifeq ($(suffix $(MAIN)),.c)
	COMPILER := $(GCC)
else ifeq ($(suffix $(MAIN)),.cpp)
	COMPILER := $(GXX)
endif

# Project files
SRC := $(wildcard ./src/*.c ./src/*.cpp)
APP := app

# Display header
display:
	@echo "\tAlgoKit Makefile C/C++"
	@echo "=========================================="

# Show compiler versions
get_version: display
	@echo "$(GCC_VERSION)"
	@echo "$(GXX_VERSION)"

# Build (auto-detect C or C++)
build: display
	@$(COMPILER) -o $(APP) $(MAIN) $(SRC)

# Run (auto-build + run)
run: build
	@./$(APP)

# Clean up
clean:
	@rm -rf $(APP)
	@echo "Cleaned up the build files."
