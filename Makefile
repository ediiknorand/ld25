CC=gcc
CC_FLAGS=-Wall -O2

SRC_DIR=src
ENGINE_DIR=engine
BUILD_DIR=build
BUILD_SUBDIR=$(ENGINE_DIR)
MODULES=engine/core engine/render
LIBS=SDL
MAIN=main.c
APP=app

define cc-modules
$(CC) -c $(CC_FLAGS) $< -o $(BUILD_DIR)/$@
endef

define cc-app
$(CC) $(CC_FLAGS) $(SRC_DIR)/$(MAIN) -o $(BUILD_DIR)/$(APP) $(addsuffix .o, $(MODULES)) $(addprefix -l, $(LIBS))
endef

$(APP): $(addsuffix .o, $(MODULES)) $(BUILD_DIR)
	$(cc-app)
	rm -f $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(MODULES)))

$(ENGINE_DIR)/%.o: $(SRC_DIR)/$(ENGINE_DIR)/%.c $(BUILD_SUBDIR)
	$(cc-modules)

$(BUILD_DIR):
	mkdir $@

$(BUILD_SUBDIR): $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/$@

clean:
	rm -f $(BUILD_DIR)/$(APP) $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(MODULES)))
