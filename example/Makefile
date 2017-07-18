INCLUDE = -I. -I.. -I../..
LIBRARY =

CXXFLAGS    = -Wall -ggdb -pthread

LINKFLAGS   = -Wl,-rpath,./:../bin
LINKFLAGS_MT = $(LINKFLAGS)

CXXFLAGS_EXTERN =
LINKFLAGS_EXTERN = -L../ -levwork -lev

TARGET_RECV   = testrecv
TARGET_SEND   = testsend

SRC_FILES   = $(wildcard *.cpp)

OBJ_FILES   = $(SRC_FILES:.cpp=.o)

$(TARGET_RECV) : testrecv.o
	g++ -o $@ $< $(CXXFLAGS) $(CXXFLAGS_EXTERN) $(LINKFLAGS_EXTERN)
$(TARGET_SEND) : testsend.o
	g++ -o $@ $< $(CXXFLAGS) $(CXXFLAGS_EXTERN) $(LINKFLAGS_EXTERN)

%.o : %.cpp
	g++ -c -o $@ $< $(CXXFLAGS) $(CXXFLAGS_EXTERN) $(INCLUDE)
%.ro : %.cpp
	g++ -c -o $@ $< $(CXXFLAGS_R) $(CXXFLAGS_EXTERN) $(INCLUDE)

.PHONY : all clean

all : $(TARGET_RECV) $(TARGET_SEND)

clean :
	-rm $(OBJ_FILES)
	-rm $(TARGET_RECV) $(TARGET_SEND)
