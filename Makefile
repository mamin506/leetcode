T := 3Sum

CPPFLAGS := -std=c++11

ifeq ($(DEBUG),1)
	CPPFLAGS += -g
endif

.PHONY: ${T} clean

${T} : build/${T}
	@echo "$^ done"

build/${T} : build/${T}.o
	g++ $(CPPFLAGS) -o $@ $^

build/${T}.o : ${T}/Solution.cpp
	@mkdir -p build
	g++ -c $(CPPFLAGS) -o $@ $^

clean:
	rm build/*
