OBJ=engine/core engine/render
LIB=SDL SDL_image
MAIN=main
APP=app

CC=gcc
CC_FLAGS=-Wall -O2

SRC=src
BUILD=build
BUILD_SUB=engine

OBJ_FILES=$(addprefix $(BUILD), $(addsuffix .o, $(OBJ)))
LIB_FLAGS=$(addprefix -l, $(LIB))
BUILD_PATHS=$(addprefix $(BUILD)/, $(BUILD_SUB))

define cc-obj
$(CC) -c $(CC_FLAGS) $< -o $@
endef

define cc-app
$(CC) $(CC_FLAGS) $(SRC)/$(MAIN).c -o $(BUILD)/$(APP) $(OBJ_FILES) $(LIB_FLAGS)
endef

$(APP): $(OBJ_FILES) $(BUILD)
	$(cc-app)
	rm -f $(OBJ_FILES)

$(BUILD)/%.o: $(SRC)/%.c $(BUILD_PATHS)
	$(cc-obj)

$(BUILD):
	mkdir $@

$(BUILD_PATHS):
	mkdir -p $@

clean:
	rm -f $(BUILD)/$(APP) $(OBJ_FILES)
