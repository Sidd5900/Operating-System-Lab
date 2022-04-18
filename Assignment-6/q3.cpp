#include <bits/stdc++.h>
using namespace std;

struct processes
{
	int arrt;
	int burstt;
	int newburstt;
	int priority;
	int compt;
	int pid;
};

struct compareSet
{
	bool operator()(processes a, processes b)
	{
		if (a.priority != b.priority)
			return a.priority < b.priority;
		else if (a.priority == b.priority)
		{
			if(a.arrt != b.arrt)
				return a.arrt < b.arrt;
			else
				return a.pid < b.pid;
		}
	}
};

bool compare(processes a, processes b)
{
	if (a.arrt < b.arrt)
		return true;
	else if (a.arrt == b.arrt)
		return a.pid < b.pid;
	else
		return false;
}

vector<processes> priorityNonPreemptive(int n, int tq, vector<processes> v, set<processes, compareSet> s)
{
	int time = 0;
	int numberOfProcesses = n;
	int it = 0;
	vector<processes> completion;
	long int totalWaitingTime = 0, totalTurnAroundTime = 0;
	while (numberOfProcesses)
	{
		if (s.empty())
		{
			s.insert(v[it]);
			time = v[it].arrt;
			it++;
		}
		processes currentProcess = *s.begin();
		s.erase(currentProcess);

		time += currentProcess.newburstt;
		currentProcess.newburstt = 0;

		currentProcess.compt = time;
		completion.push_back(currentProcess);
		numberOfProcesses--;
		totalTurnAroundTime = totalTurnAroundTime + (time - currentProcess.arrt);
		totalWaitingTime = totalWaitingTime + (time - currentProcess.arrt - currentProcess.burstt);
		while (it < n && v[it].arrt <= time)
		{
			s.insert(v[it]);
			it++;
		}
	}

	printf("%0.2f %0.2f\n", (float)totalWaitingTime / (float)n, (float)totalTurnAroundTime / (float)n);

	return completion;
}

int main()
{
	int n, tq;
	cin >> n;
	vector<processes> v;
	set<processes, compareSet> s;

	for (int i = 0; i < n; i++)
	{
		processes process;
		cin >> process.arrt >> process.burstt >> process.priority;
		process.newburstt = process.burstt;
		process.pid = i + 1;
		v.push_back(process);
	}

	sort(v.begin(), v.end(), compare);

	vector<processes> completion = priorityNonPreemptive(n, tq, v, s);

	for (int i = 0; i < n; i++)
		cout << "P" << completion[i].pid << " ";
	cout << endl;

	return 0;
}
