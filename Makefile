SDIR = src
IDIR = include
ODIR = obj

CXX=g++
CFLAGS = -Wall -I./$(IDIR)

LIBS=-lyaml-cpp

_DEPS = drafter_module.h hero.h yaml_convert.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJS = main.o drafter_module.o hero.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

drafter: $(OBJS)
	$(CXX) -g -O0 -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean: 
	rm -f drafter $(ODIR)/*.o
