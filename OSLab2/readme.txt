#Question 1:

[01/18/22]seed@VM:~/.../OSLab2$ bash q1.sh 6 2 1 2 3 2 4 2
Element 2 found at indices 0 2 4

[01/18/22]seed@VM:~/.../OSLab2$ bash q1.sh 6 2 1 2 3 2 4 5
Element not found.

#Question 2:

[01/18/22]seed@VM:~/.../OSLab2$ bash q2.sh 6
fact(6) * PrimeNoLessThan(6) = 7200

[01/18/22]seed@VM:~/.../OSLab2$ bash q2.sh 5
fact(5) * PrimeNoLessThan(5) = 1200

Question 3:

[01/18/22]seed@VM:~/.../OSLab2$ bash q3.sh 256 7
XOR of 256 and 7 = 263

[01/18/22]seed@VM:~/.../OSLab2$ bash q3.sh 256 257
XOR of 256 and 257 = 1

[01/18/22]seed@VM:~/.../OSLab2$ time ./q3.sh 256 257
XOR of 256 and 257 = 1

real	0m0.015s
user	0m0.004s
sys	0m0.000s

[01/18/22]seed@VM:~/.../OSLab2$ gcc xor.c -o xor
[01/30/22]seed@VM:~/.../OSLab2$ time ./xor 256 257
XOR of 256 and 257 = 1

real	0m0.004s
user	0m0.000s
sys	0m0.000s

Question 4:

[01/18/22]seed@VM:~/.../OSLab2$ bash q4.sh abcdef1/
Password is Valid

[01/18/22]seed@VM:~/.../OSLab2$ bash q4.sh abcdef1
Password is invalid

[01/18/22]seed@VM:~/.../OSLab2$ bash q4.sh abc/1
Invalid Password

