.PHONY: all time clean check

TST_LIB := -lcheck -lm -lpthread -lrt -lsubunit
CFLAGS := -std=c18 -g -Wextra -Wpedantic -Waggregate-return -Wwrite-strings -Wvla -Wfloat-equal
CFLAGS += -D _POSIX_C_SOURCE=200809L
CC := gcc
EXE := linklist
TST_DIR := test
BIN := bin


TST_EXE := test_linklist
SRC := src
SRC_DIR := $(wildcard $(SRC)/*.c)
TST := $(wildcard $(TST_DIR)/*.c)
TIL:= $(wildcard *.c~)
HDR:= $(wildcard *.h)
TILH:= $(wildcard *.h~)


$(EXE): $(SRC_DIR) 
	indent -linux $(SRC_DIR) $(TST)
	mkdir bin
	$(CC) $(CFLAGS) $^ -o $(BIN)/$(EXE)
	
time: 
	echo "Can you Teach me how to Makefile?"
	
all: $(EXE)
	

profile: CFLAGS += -pg
profile: LDFLAGS += -pg
profile:$(EXE)

indent:$(SRC_DIR)
		indent -linux $(SRC_DIR)

debug: CFLAGS += -g
debug:$(EXE)

clean:
	rm -f $(wildcard $(SRC)/*.c~)
	rm -f $(EXE) && rm -rf $(BIN)



	
%.o: %.c $(EXE) $(TST)
	$(CC) $(CFLAGS) -c $< -o $@
	
check: $(EXE)
	./$(BIN)/$(EXE) $(TST_DIR)/p_dict.txt $(TST_DIR)/p_test.txt

