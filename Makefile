FLAGS = -Wall -g -fPIC -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS

#if mode variable is empty, setting debug build mode
ifeq ($(mode),release)
	FLAGS += -O3 
else
	mode = debug
	FLAGS += -O0
endif

CXX=g++
INC=
LIBS=-lPocoFoundation -lPocoNet -lPocoUtil -lPocoCrypto -lPocoXML -ljson -lssl -lcrypto -lcurl $(EXTRALIBS)

OBJS= des.o common/event_loop.o common/handle_config.o common/handle_http.o common/handle_udp.o

.PHONY : clean all

all: des 

-include $(OBJS:.o=.d)

%.o: %.cpp
	$(CXX) -c $(FLAGS) $(INC) $*.cpp -o $*.o
	$(CXX) -MM $(FLAGS) $(INC) $*.cpp > $*.d

des : $(OBJS) 
	$(CXX) -o des $(OBJS) $(FLAGS) -pedantic $(INC) $(LIBS)

clean:
	/bin/rm -f $(OBJS) des *.d *.o */*.d */*.o 
