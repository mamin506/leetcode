target := a.out
obj := Solution.cpp

a.out : $(obj)
	@g++ $^ -o $(target)

debug : $(obj)
	@g++ -g $^ -o $(target)

clean :
	@rm -f $(target)
