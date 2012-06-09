CC=gcc
CC_FLAGS=-Wall -O2

SRC_DIR=src
MODULES=engine-core
LIBS=SDL
MAIN=main.c
APP=app

$(APP): $(addsuffix .o, $(MODULES))
	$(CC) $(CC_FLAGS) $(SRC_DIR)/$(MAIN) -o $(APP) $(addsuffix .o, $(MODULES)) $(addprefix -l, $(LIBS))
	rm -f $(addsuffix .o, $(MODULES))

%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CC_FLAGS) $<

clean:
	rm -f $(APP)
