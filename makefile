CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CSSFLAGS += -pendantic-errors
CXXFLAGS += -g

OBJS = Characters.o Node.o dblLinkList.o menu.o

SRCS = Characters.cpp Node.cpp dblLinkList.cpp menu.cpp

HEADERS = Characters.hpp Node.hpp dblLinkList.hpp menu.hpp

tournament: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o tournament

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm Characters.o
	rm Node.o
	rm dblLinkList.o
	rm menu.o
	rm tournament