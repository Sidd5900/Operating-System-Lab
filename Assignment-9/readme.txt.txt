Q1)
Testcase1:

3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
FIFO
F1 F2 F3
X  X  X  at time 0
7  X  X  at time 1
7  0  X  at time 2
7  0  1  at time 3
2  0  1  at time 4
2  0  1  at time 5
2  3  1  at time 6
2  3  0  at time 7
4  3  0  at time 8
4  2  0  at time 9
4  2  3  at time 10
0  2  3  at time 11
0  2  3  at time 12
0  2  3  at time 13
0  1  3  at time 14
0  1  2  at time 15
0  1  2  at time 16
0  1  2  at time 17
7  1  2  at time 18
7  0  2  at time 19
7  0  1  at time 20
#Page faults: 15

LRU
F1 F2 F3
X  X  X  at time 0
7  X  X  at time 1
7  0  X  at time 2
7  0  1  at time 3
2  0  1  at time 4
2  0  1  at time 5
2  0  3  at time 6
2  0  3  at time 7
4  0  3  at time 8
4  0  2  at time 9
4  3  2  at time 10
0  3  2  at time 11
0  3  2  at time 12
0  3  2  at time 13
1  3  2  at time 14
1  3  2  at time 15
1  0  2  at time 16
1  0  2  at time 17
1  0  7  at time 18
1  0  7  at time 19
1  0  7  at time 20
#Page faults: 12

OPTIMAL
F1 F2 F3
X  X  X  at time 0
7  X  X  at time 1
7  0  X  at time 2
7  0  1  at time 3
2  0  1  at time 4
2  0  1  at time 5
2  0  3  at time 6
2  0  3  at time 7
2  4  3  at time 8
2  4  3  at time 9
2  4  3  at time 10
2  0  3  at time 11
2  0  3  at time 12
2  0  3  at time 13
2  0  1  at time 14
2  0  1  at time 15
2  0  1  at time 16
2  0  1  at time 17
7  0  1  at time 18
7  0  1  at time 19
7  0  1  at time 20
#Page faults: 9

Best Page Replacement Algorithm: OPTIMAL



Testcase 2:

4
1 2 3 4 2 7 5 1 1 6 4 7 2 1 2 5
FIFO
F1 F2 F3 F4
X  X  X  X  at time 0
1  X  X  X  at time 1
1  2  X  X  at time 2
1  2  3  X  at time 3
1  2  3  4  at time 4
1  2  3  4  at time 5
7  2  3  4  at time 6
7  5  3  4  at time 7
7  5  1  4  at time 8
7  5  1  4  at time 9
7  5  1  6  at time 10
4  5  1  6  at time 11
4  7  1  6  at time 12
4  7  2  6  at time 13
4  7  2  1  at time 14
4  7  2  1  at time 15
5  7  2  1  at time 16
#Page faults: 13

LRU
F1 F2 F3 F4
X  X  X  X  at time 0
1  X  X  X  at time 1
1  2  X  X  at time 2
1  2  3  X  at time 3
1  2  3  4  at time 4
1  2  3  4  at time 5
7  2  3  4  at time 6
7  2  5  4  at time 7
7  2  5  1  at time 8
7  2  5  1  at time 9
7  6  5  1  at time 10
4  6  5  1  at time 11
4  6  7  1  at time 12
4  6  7  2  at time 13
4  1  7  2  at time 14
4  1  7  2  at time 15
5  1  7  2  at time 16
#Page faults: 13

OPTIMAL
F1 F2 F3 F4
X  X  X  X  at time 0
1  X  X  X  at time 1
1  2  X  X  at time 2
1  2  3  X  at time 3
1  2  3  4  at time 4
1  2  3  4  at time 5
1  2  7  4  at time 6
1  5  7  4  at time 7
1  5  7  4  at time 8
1  5  7  4  at time 9
1  6  7  4  at time 10
1  6  7  4  at time 11
1  6  7  4  at time 12
1  2  7  4  at time 13
1  2  7  4  at time 14
1  2  7  4  at time 15
5  2  7  4  at time 16
#Page faults: 9

Best Page Replacement Algorithm: OPTIMAL

//----------------------------------------------------------------------------

Q2)

4
1 2 3 4 2 7 5 1 1 6 4 7 2 1 2 5
MRU
F1 F2 F3 F4
X  X  X  X  at time 0
1  X  X  X  at time 1
1  2  X  X  at time 2
1  2  3  X  at time 3
1  2  3  4  at time 4
1  2  3  4  at time 5
1  7  3  4  at time 6
1  5  3  4  at time 7
1  5  3  4  at time 8
1  5  3  4  at time 9
6  5  3  4  at time 10
6  5  3  4  at time 11
6  5  3  7  at time 12
6  5  3  2  at time 13
6  5  3  1  at time 14
6  5  3  2  at time 15
6  5  3  2  at time 16
#Page faults: 11

As we can see here that MRU (Most Recently Used Page Replacement) beats FIFO and LRU page replacement.
