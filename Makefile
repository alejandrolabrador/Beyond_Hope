#This is our MakeFile. 

CXX =g++ -std=c++17
GAME = Beyond_Hope.out

INCLUDEDIR = ./include
SRCDIR = ./sources

INCLUDES = $(wildcard $(INCLUDEDIR)/*.hpp)
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(GAME)

$(GAME): $(OBJS)
	$(CXX) $^ -o $@ -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -I$(INCLUDEDIR) -o $@

clean:
	$(RM) $(OBJS) $(GAME)

run:
	./$(GAME)

