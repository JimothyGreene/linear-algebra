# Variables
CXX=g++
CXXFLAGS=-Wall -g
OBJDIR=obj

vpath %.h src
vpath %.cpp src

objects = $(addprefix $(OBJDIR)/, vector.o main.o)

linear-algebra: $(objects)
	$(CXX) $(CXXFLAGS) $(objects) -o $@

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: linear-algebra
	./linear-algebra

clean:
	rm $(objects) linear-algebra
