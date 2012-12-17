OBJ=engine/core engine/render engine/sound engine/text dbt/main_scene dbt/map dbt/input dbt/entity dbt/render_entity dbt/path dbt/refresh_entity dbt/attack dbt/status dbt/player dbt/wave
LIB=SDL SDL_image SDL_mixer SDL_ttf m
MAIN=main
APP=ld25-dbt

CC=gcc
CC_FLAGS=-Wall -O3

SRC=src
OBJ_PATH=obj
OBJ_SUB=engine gui dbt
BUILD=dbt

OBJ_FILES=$(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(OBJ)))
LIB_FLAGS=$(addprefix -l, $(LIB))
OBJ_PATHS=$(addprefix $(OBJ_PATH)/, $(OBJ_SUB))

define cc-obj
$(CC) -c $(CC_FLAGS) $< -o $@
endef

define cc-app
$(CC) $(CC_FLAGS) $(SRC)/$(MAIN).c -o $(BUILD)/$(APP) $(OBJ_FILES) $(LIB_FLAGS)
endef

$(APP): $(OBJ_FILES) $(OBJ_PATH) $(BUILD)
	$(cc-app)
	rm -f $(OBJ_FILES)

$(BUILD):
	mkdir $(BUILD)

$(OBJ_PATH)/%.o: $(SRC)/%.c $(OBJ_PATHS)
	$(cc-obj)

$(OBJ_PATH):
	mkdir $@

$(OBJ_PATHS):
	mkdir -p $@

clean:
	rm -f $(BUILD)/$(APP) $(OBJ_FILES)
