src = $(wildcard *.cpp)
obj = $(src:.c=.o)
CPPFLAGS = -std=c++14 -g -O3

Sort: $(obj)
	$(CXX) -o $@ $^ $(CPPFLAGS)
.PHONY: clean
clean:
	rm -f $(obj) Sort
