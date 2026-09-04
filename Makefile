# compile aux
CC=gcc
CFLAGS=-Wall -Wextra -Werror

# source files directories
SRC_DIR=./src
TEST_DIR=./tests
TEST_SUBJECTS=$(wildcard $(TEST_DIR)/*)

# source files
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
TEST_FILES=$(foreach subj,$(TEST_SUBJECTS),$(wildcard $(subj)/*.c))

# output files directories
DEST_DIR=./dest
OBJ_DIR=$(DEST_DIR)/objs
TEST_DEST_DIR=$(DEST_DIR)/tests
TEST_SUBJECTS_DEST_DIR=$(patsubst $(TEST_DIR)/%,$(TEST_DEST_DIR)/%,$(TEST_SUBJECTS))

# output files
OBJS_FILES=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# this must change to an actual function
TEST_BIN_FILES=$(TEST_DEST_DIR)/vector/init_deinit.out

# this recipe is used just to display on terminal (visual debugging :^(   )
vars:
	@echo "SRC_DIR: $(SRC_DIR)"
	@echo "TEST_DIR: $(TEST_DIR)"
	@echo "TEST_SUBJECTS: $(TEST_SUBJECTS)"
	@echo "SRC_FILES: $(SRC_FILES)"
	@echo "TEST_FILES: $(TEST_FILES)"
	@echo "DEST_DIR: $(DEST_DIR)"
	@echo "OBJ_DIR: $(OBJ_DIR)"
	@echo "TEST_DEST_DIR: $(TEST_DEST_DIR)"
	@echo "TEST_SUBJECTS_DEST_DIR: $(TEST_SUBJECTS_DEST_DIR)"
	@echo "OBJS_FILES: $(OBJS_FILES)"
	@echo "TEST_BIN_FILES: $(TEST_BIN_FILES)"

# WARN: this code bellow is kinda bad and certainly will need fixes in the future.

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(dir $(TEST_DEST_DIR)/%):
	mkdir -p $@

$(TEST_SUBJECTS_DEST_DIR):
	mkdir -p $@

$(TEST_SUBJECTS_DEST_DIR)/%.out: $(TEST_SUBJECTS)/%.c $(OBJS_FILES) $(TEST_SUBJECTS_DEST_DIR)
	$(CC) $(CFLAGS) $< $(OBJS_FILES) -o $@

build: $(OBJS_FILES) $(TEST_BIN_FILES)

clean: $(DEST_DIR)
	rm -rf $(DEST_DIR)

test:
	@exit_code=0;                                                 \
	for f in $(TEST_BIN_FILES); do                                \
		if [ ! -f $$f ]; then                                       \
			echo "$$f file doesn't exists. (run make build instead)"; \
			exit_code=1;                                              \
			continue;                                                 \
		fi;                                                         \
		output=$$("$$f" 2>&1);                                      \
		if [ $$? -ne 0 ]; then                                      \
			echo "[ failed ] $$f:";                                   \
			echo "$$output";                                          \
		else                                                        \
			echo "[ passed ] $$f";                                    \
		fi                                                          \
	done;                                                         \
	exit $$exit_code;

.PHONY: build clean test vars
