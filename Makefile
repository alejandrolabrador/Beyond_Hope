CXX = g++ -std=c++17
GAME = Beyond_Hope.out

INCLUDEDIR = ./include
SRCDIR = ./sources
OBJDIR = ./objects

INCLUDES = $(wildcard $(INCLUDEDIR)/*.hpp)
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

#You need to add ur own path to the library in lib and include
DSG_INCLUDE = /home/jhoseline/DeSiGNAR/include
DSG_LIB =  /home/jhoseline/DeSiGNAR/lib
CXX += -I$(DSG_INCLUDE) -L$(DSG_LIB) -lDesignar

all: $(GAME)

$(GAME): $(OBJS)
	$(CXX) $^ -o $@ -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -lDesignar

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -I$(INCLUDEDIR) -o $@

clean:
	$(RM) $(OBJS) $(GAME)

run:
	./$(GAME)