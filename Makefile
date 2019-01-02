a.out:
	g++ main.cpp student.cpp -o a.out

.PHONY:clean
clean:
	rm -rf a.out
