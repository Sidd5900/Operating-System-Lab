#include <bits/stdc++.h>

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
bool at_comp(struct Process p1, struct Process p2) {
	if (p1.arrt == p2.arrt) return p1.pid < p2.pid;
	return p1.arrt < p2.arrt;
}

/* Comparator to sort according to finish times */
bool ft_comp(struct Process p1, struct Process p2) {
	return p1.compt < p2.compt;
}

/* Operator overloading to sort according to burst times */
struct compareRemainingTime {
	bool operator()(struct Process* p1, struct Process* p2) {
		if (p1 -> remt == p2 -> remt) return p1 -> pid > p2 -> pid;
		return p1 -> remt < p2 -> remt;
	}
};


vector<int> order;


// Longest Remaining Time First Algorithm
void lrtf(vector<struct Process> &process) {
	int n = process.size();
	int queued = 0;
	int time = 0;

	// Sort vector according to arrival times
	sort(process.begin(), process.end(), at_comp);

	priority_queue<Process*, vector<Process*>, compareRemainingTime> pq;

	while (true) {
		// If all finished, break
		if (pq.empty() && queued == n) break;

		// If queue is empty, increase time
		if (pq.empty()) time = max(time, process[queued].arrt);

		// Push all processes whose arrival time <= time
		while (time >= process[queued].arrt && queued < n){
			pq.push(&process[queued]);
			queued++;
		}

		// Extract shortest remaining burst time process
		Process* p = pq.top();
		pq.pop();

		// Calculate WT, FT, TAT, RT (Update BT), LET
		time += min(TQ, p -> remt);
		p -> remt -= min(TQ, p -> remt);
		if (p -> remt == 0) {
			p -> compt = time;
			p -> turnt = p -> compt - p -> arrt;
			p -> waitt = p -> turnt - p -> burstt;
		} else pq.push(p);
	}

	return;
}



int main()
{
    int n;
    cin>>n;
    int a,b;
    vector<struct Process> proc(n);
    for (int i = 0; i < n; i++) {
		proc[i].pid = i + 1;
		cin >> proc[i].arrt >> proc[i].burstt;
		proc[i].remt = proc[i].burstt;
	}


    lrtf(proc);

    double avg_wt = 0.0;
    double avg_tat = 0.0;
    for(auto p : proc)
    {
        avg_wt+= (double)p.waitt;
        avg_tat+= (double)p.turnt;
    }

    avg_tat/=n;
    avg_wt/=n;

    cout << fixed << setprecision(2)<< avg_wt << " " << avg_tat << endl;

    for(auto o: order)
        cout<<"P"<<o<<" ";

}
