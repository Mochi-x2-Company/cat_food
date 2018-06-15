cc = gcc
lname = -o LongInt
main0 = -o TestIni
main1 = -o TestMlt
main2 = -o TestDiv
main3 = -o TestApp

LongInt: LongInt.c
	$(cc) $(lname) LongInt.c

TestIni: TestIni.c BigNumLib.c BigNumMlt.c BigNumDiv.c BigNumLib.h
	$(cc) $(main0) TestIni.c BigNumLib.c BigNumMlt.c BigNumDiv.c

TestMlt: TestMlt.c BigNumLib.c BigNumMlt.c BigNumDiv.c BigNumLib.h
	$(cc) $(main1) TestMlt.c BigNumLib.c BigNumMlt.c BigNumDiv.c

TestDiv: TestDiv.c BigNumLib.c BigNumMlt.c BigNumDiv.c BigNumLib.h
	$(cc) $(main2) TestDiv.c BigNumLib.c BigNumMlt.c BigNumDiv.c

TestApp: TestApp.c BigNumLib.c BigNumMlt.c BigNumDiv.c BigNumLib.h
	$(cc) $(main3) TestApp.c BigNumLib.c BigNumMlt.c BigNumDiv.c
