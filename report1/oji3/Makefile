cc = gcc
main = Test
opt = 3

main: BigNumDiv.c BigNumLib.c BigNumLib.h BigNumMlt.c Test.c
	$(cc) -o $(main) -DOPT=$(opt) BigNumDiv.c BigNumLib.c BigNumMlt.c Test.c

TestDiv: BigNumDiv.c BigNumLib.c BigNumLib.h BigNumMlt.c TestDiv.c
	$(cc) -o div BigNumDiv.c BigNumLib.c BigNumMlt.c TestDiv.c

testo: BigNumDiv.c BigNumLib.c BigNumLib.h BigNumMlt.c ojisantest.c
	$(cc) -o div BigNumDiv.c BigNumLib.c BigNumMlt.c ojisantest.c
clean:
	rm -f *.o *.exe 
