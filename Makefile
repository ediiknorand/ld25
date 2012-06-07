CC=gcc
CC_FLAGS=-Wall -O2

SRC_DIR=src
MODULES=
LIBS=SDL
MAIN=main
APP=app

$(APP): $(addsuffix .o, $(MODULES))
	$(CC) $(SRC_DIR)/$(MAIN) -o $(APP) $(addsuffix .o, $(MODULES))
	rm -f $(addsuffix .o, $(MODULES))

%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CC_FLAGS) $<

clean:
	rm -f $(APP)
