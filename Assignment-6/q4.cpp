#include <bits/stdc++.h>
#define TIME_QUANTUM 1
using namespace std;

struct Process
{
    int pid;
    int arrt;
    int burstt;
    int compt;
    int waitt;
    int turnt;
    int remt;
};

const int TQ=1;

/* Comparator to sort according to arrival times */
bool arrt_comp(Process p1, Process p2) {
	if (p1.arrt == p2.arrt) return p1.pid < p2.pid;
	return p1.arrt < p2.arrt;
}

/* Comparator to sort according to finish times */
bool compt_comp(Process p1, Process p2) {
	return p1.compt < p2.compt;
}

/* Operator overloading to sort according to burst times */
struct compareRemTime {
	bool operator()(Process* p1, Process* p2) {
		if (p1 -> remt == p2 -> remt) return p1 -> pid > p2 -> pid;
		return p1 -> remt < p2 -> remt;
	}
};

// Longest Remaining Time First Algorithm
void lrtf(vector<Process> &process) {
	int n = process.size();
	int queued = 0;
	int time = 0;

	// Sort vector according to arrival times
	sort(process.begin(), process.end(), arrt_comp);

	priority_queue<Process*, vector<Process*>, compareRemTime> pq;

	while (true) {
		if (pq.empty() && queued == n) break;
		if (pq.empty()) time = max(time, process[queued].arrt);

		while (time >= process[queued].arrt && queued < n){
			pq.push(&process[queued]);
			queued++;
		}

		Process* p = pq.top();
		pq.pop();

		time += min(TIME_QUANTUM, p -> remt);
		p -> remt -= min(TIME_QUANTUM, p -> remt);
		if (p -> remt == 0) {
			p -> compt = time;
			p -> turnt = p -> compt - p -> arrt;
			p -> waitt = p -> turnt - p -> burstt;
		} else pq.push(p);
	}

	return;
}



int main() {
	// Number of processes
	int n;
	cin >> n;

	// Vector of processes
	vector<Process> process(n);
	for (int i = 0; i < n; i++) {
		process[i].pid = i + 1;
		cin >> process[i].arrt >> process[i].burstt;
		process[i].remt = process[i].burstt;
	}

	// Find WT and TAT for all processes
	lrtf(process);
	// Print average WT and average TAT

    double avg_wt = 0.0;
	double avg_tat = 0.0;

	for (auto p: process) {
		avg_wt += p.waitt;
		avg_tat += p.turnt;
	}

	avg_wt /= n;
	avg_tat /= n;
	cout << fixed << setprecision(2);
	cout << avg_wt << " " << avg_tat << endl;

	// Sort vector according to finish times
	sort(process.begin(), process.end(), compt_comp);

	for (int i = 0; i < n; i++) {
		cout << "P" << process[i].pid << " ";
	}
	cout << endl;
}
