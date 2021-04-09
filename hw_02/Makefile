CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17 -Iinclude -g
LDFLAGS = -lncurses

EXE = hw_02
EXE2 = test_hw_02
SRCDIR = src
SRCDIR2 = test
OBJDIR = obj

OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(wildcard $(SRCDIR)/*.cpp))
TESTOBJECTS = $(patsubst $(SRCDIR2)/%.cpp,$(OBJDIR)/%.o,$(wildcard $(SRCDIR2)/*.cpp)) obj/Board.o

all: $(EXE) $(EXE2)

$(EXE): $(OBJDIR) $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXE) $(LDFLAGS)

$(EXE2): $(OBJDIR) $(TESTOBJECTS)
	$(CXX) $(TESTOBJECTS) -o $(EXE2)
  
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR2)/%.cpp
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

include $(wildcard $(BINDIR)/*.d)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(EXE) $(EXE2)

.PHONY: clean all