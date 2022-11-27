# SystemProgramming_Assignment2

<b>making libman.so</b> <br>
gcc -fpic -shared -o libman.so man.c
<br>

<b>making libeuc.so</b> <br>
gcc -fpic -shared -o libeuc.so euc.c -lm
<br>

<b>run program</b><br>
./prog input.txt<br>

*dms 파일들은 개발 과정 중에 생긴 파일들임
