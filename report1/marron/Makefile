cc = gcc
main = Test

main: BigNumDiv.c BigNumLib.c BigNumLib.h BigNumMlt.c Test.c
	$(cc) -o $(main) -DOPT=$(opt) BigNumDiv.c BigNumLib.c BigNumMlt.c Test.c

clean:
	rm -f *.o *.exe