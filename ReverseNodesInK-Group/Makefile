target := a.out
obj := Solution.cpp

a.out : $(obj)
	@g++ -std=c++11 $^ -o $(target)

debug : $(obj)
	@g++ -g -std=c++11 $^ -o $(target)

clean :
	@rm -f $(target)
