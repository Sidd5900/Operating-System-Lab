Q1)
[03/08/22]seed@VM:~/.../OSLab7$ gcc q1.c -o q1 -lpthread
[03/08/22]seed@VM:~/.../OSLab7$ ./q1
Writing....Writer 2 updates sharedVariable to 2
Writing....Writer 1 updates sharedVariable to 3
Reading...Reader 5 reads sharedVariable which equals 3
Reading...Reader 4 reads sharedVariable which equals 3
Reading...Reader 3 reads sharedVariable which equals 3
Reading...Reader 2 reads sharedVariable which equals 3
Reading...Reader 1 reads sharedVariable which equals 3

Q2)
After wait(mutex) of process A and then wait(data) of process B, we enter a deadlock state as now none of the process can enter the critical section.
Deadlock can be avoided as follows:

semaphore *mutex, *data;
void A() {
wait(mutex);
wait(data);
printf("process A")
signal(mutex);
signal(data);
}

void B() {
wait(mutex);
wait(data);
printf("process B")
signal(mutex);
signal(data);
}

EXecution:

process Aprocess B[03/08/22]seed@VM:~/.../OSLab7$ gcc q2.c -o q2 -lpthread
[03/08/22]seed@VM:~/.../OSLab7$ ./q2
process Aprocess B

Q3)

[03/08/22]seed@VM:~/.../OSLab7$ gcc q3.c -o q3 -lpthread
[03/08/22]seed@VM:~/.../OSLab7$ ./q3
Student 6 picked up a slice and started studying. Slices left = 4
Student 5 picked up a slice and started studying. Slices left = 3
Student 4 picked up a slice and started studying. Slices left = 2
Student 7 picked up a slice and started studying. Slices left = 1
Student 8 picked up a slice and started studying. Slices left = 0
Student 3 ordered pizza as no slices left and went to sleep
Pizza delivered...Slice Count =  5
Student 2 picked up a slice and started studying. Slices left = 4
Student 1 picked up a slice and started studying. Slices left = 3
Student 6 picked up a slice and started studying. Slices left = 2
Student 5 picked up a slice and started studying. Slices left = 1
Student 4 picked up a slice and started studying. Slices left = 0
Student 7 ordered pizza as no slices left and went to sleep
Student 8 went to sleep as no slices left.
Pizza delivered...Slice Count =  5
Student 3 picked up a slice and started studying. Slices left = 4
Student 2 picked up a slice and started studying. Slices left = 3
Student 1 picked up a slice and started studying. Slices left = 2
Student 6 picked up a slice and started studying. Slices left = 1
Student 5 picked up a slice and started studying. Slices left = 0
Student 4 ordered pizza as no slices left and went to sleep
Student 7 went to sleep as no slices left.
Student 8 went to sleep as no slices left.
Pizza delivered...Slice Count =  5
Student 3 picked up a slice and started studying. Slices left = 4
Student 2 picked up a slice and started studying. Slices left = 3
Student 1 picked up a slice and started studying. Slices left = 2
...





