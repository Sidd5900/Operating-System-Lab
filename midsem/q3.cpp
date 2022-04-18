#include <bits/stdc++.h>
using namespace std;

const int TQ[] = {4, 3};

// A class of a single process
struct Process {
	int pid;	// Process ID
	int arrt;		// Arrival Time
	int burstt;		// Burst Time
	int compt;		// completion Time
	int remt;		// Remaining Time
	int priort;	// Priority
};

//Comparator to sort Processes according to arrival times
bool arrt_comp(Process p1, Process p2)
{
	if (p1.arrt == p2.arrt)
        return p1.pid < p2.pid;
	return p1.arrt < p2.arrt;
}

//Comparator to sort Processes according to completion times
bool compt_comp(Process p1, Process p2)
{
	return p1.compt < p2.compt;
}

//Updates time and inserts processes which have arrived in ready queue
void updateTimeAndReadyQueue(int &time, int updated_time, vector<Process> &process, vector<queue<Process*>> &ready, int &queued)
{
	int n = process.size();
	time = updated_time;
	while (time >= process[queued].arrt && queued < n)
    {
		ready[process[queued].priort - 1].push(&process[queued]);
		queued++;
	}
	return;
}

//Returns the minimum queue number which is non empty. If all are empty, returns -1
int nextNonEmptyQueue(vector<queue<Process*>> ready)
{
	int no_of_queues = ready.size();
	for (int i = 0; i < no_of_queues; i++)
    {
		if (!ready[i].empty())
            return i;
	}
	return -1;
}

// Multi Level Queue Scheduling Algorithm
void multiLevelQueue(vector<Process> &process, int no_of_queues) {
	int n = process.size();
	int queued = 0;
	int time = 0;

	// Sort Processes according to arrival times
	sort(process.begin(), process.end(), arrt_comp);

	// Ready queue
	vector<queue<Process*>> ready(no_of_queues);

	while (1)
    {
		// If all queues are empty
		if (nextNonEmptyQueue(ready) == -1)
		{
			// If all processes had already arrived, break
			if (queued == n)
                break;
			updateTimeAndReadyQueue(time, max(time, process[queued].arrt), process, ready, queued);
		}

		// Extract first process from ready queue
		int next_ready = nextNonEmptyQueue(ready);
		Process* p = ready[next_ready].front();
		ready[next_ready].pop();

		//take minimum of time quantum and remaining time as the updated time
		updateTimeAndReadyQueue(time, time + min(TQ[next_ready], p -> remt), process, ready, queued);
		p -> remt -= min(TQ[next_ready], p -> remt);

		//if process completely executed, assign completion time
		if (p -> remt == 0)
            p -> compt = time;
		else
            ready[next_ready].push(p);
	}
}


int main() {
	// Number of processes and number of queues(here 2)
	int n, no_of_queues;
	cin >> n >> no_of_queues;

	//Take input in vector of processes
	vector<Process> process(n);
	for (int i = 0; i < n; i++)
    {
		process[i].pid = i + 1;
		cin >> process[i].arrt >> process[i].burstt >> process[i].priort;
		process[i].remt = process[i].burstt;
	}

	//multi level queue scheduling
	multiLevelQueue(process, no_of_queues);

	double avg_wt = 0.0;
	double avg_tat = 0.0;

	//compute avg turn around time and avg waiting time
	for (auto p: process)
    {
		avg_tat += p.compt - p.arrt;
		avg_wt += (p.compt - p.arrt) - p.burstt;
	}

	avg_wt /= n;
	avg_tat /= n;
	cout << fixed << setprecision(2)<< "Avg_WT = " << avg_wt << " Avg_TAT = " << avg_tat << endl;

	// Sort vector according to completion times
	sort(process.begin(), process.end(), compt_comp);

	//print order of execution of processes
	for (int i = 0; i < n; i++)
    {
		cout << "P" << process[i].pid << " ";
	}
	cout << endl;
}
