# set output directory
OUTPUT_DIR = tmp/

# set target
TARGET = 

# get all directories
DIRECTORIES = $(dir $(wildcard */))

# get all cases could be made
ALLCASE = $(patsubst $(OUTPUT_DIR), , $(DIRECTORIES))

.PHONY: all clean 4Sum

all : 
	@echo $(ALLCASE)

% : %/Solution.cpp
	@echo here
	@cd $(@D) && ls

clean :
	@echo cleaning

FORCE :
