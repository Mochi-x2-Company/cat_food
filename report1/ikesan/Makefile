cc = gcc
lname = -o LongInt
main0 = -o TestIni
main1 = -o TestMlt
main2 = -o TestDiv
main3 = -o TestApp
main4 = -o q1

LongInt: LongInt.c
	$(cc) $(lname) LongInt.c

TestIni: TestIni.c BigNumLib.c BigNumMlt.c BigNumDiv.c
	$(cc) $(main0) TestIni.c BigNumLib.c BigNumMlt.c BigNumDiv.c

TestMlt: TestMlt.c BigNumLib.c BigNumMlt.c BigNumDiv.c
	$(cc) $(main1) TestMlt.c BigNumLib.c BigNumMlt.c BigNumDiv.c

TestDiv: TestDiv.c BigNumLib.c BigNumMlt.c BigNumDiv.c
	$(cc) $(main2) TestDiv.c BigNumLib.c BigNumMlt.c BigNumDiv.c

TestApp: TestApp.c BigNumLib.c BigNumMlt.c BigNumDiv.c
	$(cc) $(main3) TestApp.c BigNumLib.c BigNumMlt.c BigNumDiv.c

q1: q1.c q1lib.c BigNumMlt.c BigNumDiv.c
	$(cc) $(main4) q1.c q1lib.c BigNumMlt.c BigNumDiv.c