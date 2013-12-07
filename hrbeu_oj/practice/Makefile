SRC:=$(shell ls *.c)
all:$(SRC)
	gcc -Wall -m32 $(SRC)
run:all
	bash "cat <<EOF | ./a.out"
.PHONY:clean
clean:
	@rm a.out
