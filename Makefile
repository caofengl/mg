a.out:
	g++ -o a.out -g main.cpp student.cpp

.PHONY:clean
clean:
	rm -rf a.out
