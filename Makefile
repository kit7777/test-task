CC=g++ 
CFLAGS=-c -Wall -std=c++17
LDFLAGS=
SOURCES_APP=source/main.cpp source/consApp.cpp
SOURCES_LIB=source/Journal.cpp source/Message.cpp
LIB=buildLib
EXECUTABLE=main
OBJECTS_LIB=$(SOURCES_LIB:.cpp=.o)
OBJECTS_APP=$(SOURCES_APP:.cpp=.o)

all: $(SOURCES_LIB) $(LIB) $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES_APP) $(OBJECTS_APP)
	$(CC) $(LDFLAGS) $(OBJECTS_APP) -o $(EXECUTABLE).out ./$(LIB).so

$(LIB): $(OBJECTS_LIB)
	$(CC) -shared $(OBJECTS_LIB) -o $@.so

.cpp.o:
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean: 
	rm  -rf ./source/main.o ./source/Journal.o ./source/Message.o .source/consApp.o 
run:
	./main.out

 
