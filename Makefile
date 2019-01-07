# a.out:
#     g++ -o a.out -g main.cpp student.cpp

src=$(wildcard *.cpp)
obj=$(patsubst %.cpp, %.o, $(src))

./a.out:$(obj)
	g++ -o $@ $^

$(obj):%.o:%.cpp
	g++ -std=c++11 -o $@ -c $< -g

.PHONY:clean
clean:
	rm -rf a.out $(obj)
