include ../makefile.env
WORKROOT=../../
CC=g++

TARGET=libmyserver.a
OBJS=queue.o socket.o util.o epollserver.o myserver.o

INCS=\
	-I$(MYLOG_PATH)include \
	-I$(MYCONF_PATH)include \
	-I$(RAPID_JSON_PATH)include 

LIBS=\
	-L$(MYLOG_PATH)lib \
	-L$(MYCONF_PATH)lib \
	-Wl,-whole-archive -lmylog -Wl,-no-whole-archive \
	-Wl,-whole-archive -lmyconf -Wl,-no-whole-archive \
	-lpthread

CPPFLAGS=$(INCS)  -Wall -W -pipe -Wno-unused-parameter -g -O2 
LDFLAGS=$(LIBS) -O2

.PHONY : all

all: clean $(TARGET)

$(TARGET) : $(OBJS)
	mkdir -p ../output/include
	mkdir -p ../output/lib
	cp *h ../output/include
	ar -r $(TARGET) $(OBJS)
	cp *.a ../output/lib

$(OBJS) :%.o : %.cpp 
	$(CC) -c $(CPPFLAGS) $< 

.PHONY : clean
clean:
	rm -rf $(OBJS) $(TARGET)
	rm -rf ../output/include
	rm -rf ../output/lib
