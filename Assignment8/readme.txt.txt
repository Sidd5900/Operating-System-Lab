Testcase 1:
Enter the number of processes
5
Enter the number of resources
3
Enter the allocation matrix (resources already allocated to each process)
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the max matrix (maximum resources needed for each process)
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Enter the available resources (number of instances of each resource available)
3 3 2
Safe sequence exists:
P1 P3 P0 P2 P4
P1 P3 P0 P4 P2
P1 P3 P2 P0 P4
P1 P3 P2 P4 P0
P1 P3 P4 P0 P2
P1 P3 P4 P2 P0
P1 P4 P3 P0 P2
P1 P4 P3 P2 P0
P3 P1 P0 P2 P4
P3 P1 P0 P4 P2
P3 P1 P2 P0 P4
P3 P1 P2 P4 P0
P3 P1 P4 P0 P2
P3 P1 P4 P2 P0
P3 P4 P1 P0 P2
P3 P4 P1 P2 P0



Testcase 2:
Enter the number of processes
5
Enter the number of resources
3
Enter the allocation matrix (resources already allocated to each process)
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the max matrix (maximum resources needed for each process)
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Enter the available resources (number of instances of each resource available)
1 1 1
Deadlock detected (No safe sequence possible)



Testcase 3:
Enter the number of processes
5
Enter the number of resources
3
Enter the allocation matrix (resources already allocated to each process)
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the max matrix (maximum resources needed for each process)
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Enter the available resources (number of instances of each resource available)
2 1 1
Deadlock detected (No safe sequence possible)




Testcase4:
Enter the number of processes
5
Enter the number of resources
3
Enter the allocation matrix (resources already allocated to each process)
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the max matrix (maximum resources needed for each process)
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Enter the available resources (number of instances of each resource available)
5 3 1
Safe sequence exists:
P3 P1 P2 P0 P4
P3 P1 P2 P4 P0
P3 P1 P4 P0 P2
P3 P1 P4 P2 P0
P3 P2 P0 P1 P4
P3 P2 P0 P4 P1
P3 P2 P1 P0 P4
P3 P2 P1 P4 P0
P3 P2 P4 P0 P1
P3 P2 P4 P1 P0
P3 P4 P0 P1 P2
P3 P4 P0 P2 P1
P3 P4 P1 P0 P2
P3 P4 P1 P2 P0
P3 P4 P2 P0 P1
P3 P4 P2 P1 P0
P4 P1 P2 P3 P0
P4 P1 P3 P0 P2
P4 P1 P3 P2 P0
P4 P3 P0 P1 P2
P4 P3 P0 P2 P1
P4 P3 P1 P0 P2
P4 P3 P1 P2 P0
P4 P3 P2 P0 P1
P4 P3 P2 P1 P0
