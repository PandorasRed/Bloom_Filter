CPP=g++

INC=include
CFLAGS= -g -Wall -Wextra -Werror 
NAME=bloomTest
SRC_FILES = bloomTest.cpp readFastaFile.cpp kmer.cpp bloomFilter.cpp hash.cpp
SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(patsubst %.cpp, %.o, $(SRCS))


all: clean $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@ -I./$(INC)

clean:
	rm -f $(OBJS) $(NAME)
