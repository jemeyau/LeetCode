CXX = g++
CC = gcc

SRC_DIR = ./
BIN_DIR = ./
TMP_DIR = ./tmp 

C_LIST := $(notdir $(wildcard $(SRC_DIR)/*.c))
C_TARGETS := $(addsuffix .a, $(basename $(C_LIST)))

CPP_TARGETS := $(addsuffix .a, $(basename $(notdir $(wildcard $(SRC_DIR)/*.cpp))))

#没有中间目标文件
#OBJS := $(addprefix $(TMP_DIR)/, $(addsuffix .o, $(basename $(C_LIST))))

#$(info CPP_TARGETS=$(CPP_TARGETS))

all : $(C_TARGETS) $(CPP_TARGETS)

$(filter %.a, $(C_TARGETS)) : %.a : %.c 
	$(CC) $^ -o $@

$(filter %.a, $(CPP_TARGETS)) : %.a : %.cpp 
	$(CXX) $^ -o $@

#$(OBJS) : %.c 
#	$(CC) $< -o $@

.PHONY : clean all

clean :
	@rm -rf $(BIN_DIR)/*.a 
	@rm -rf $(TMP_DIR)/*.o
