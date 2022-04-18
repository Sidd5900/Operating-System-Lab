#include<bits/stdc++.h>
using namespace std;


struct processes
{
 int arrt;
 int burstt;
 int newburstt;
 int compt;
 int pid;
};

bool compare(processes a, processes b)
{
 if(a.arrt < b.arrt)
   return true;

 else if(a.arrt == b.arrt)
   return a.pid < b.pid;

 else
   return false;
}

vector<processes> roundRobin(int n, int tq, vector<processes> v, queue<processes> q)
{
  int time = 0;
  int numberOfProcesses = n;
  int it = 0;

  vector<processes> completion;

  long int totalWaitingTime = 0, totalTurnAroundTime = 0;

  while (numberOfProcesses)
  {
    if (q.empty())
    {
      q.push(v[it]);
      time = v[it].arrt;
      it++;
    }

    processes currentProcess = q.front();
    q.pop();
    int spent = min(currentProcess.newburstt, tq);
    currentProcess.newburstt -= spent;
    time += spent;
    if (currentProcess.newburstt > 0)
    {
      while (it < n && v[it].arrt <= time)
      {
        q.push(v[it]);
        it++;
      }
      q.push(currentProcess);
    }

    else
    {
      currentProcess.compt = time;
      completion.push_back(currentProcess);
      numberOfProcesses--;
      totalTurnAroundTime += time - currentProcess.arrt;
      totalWaitingTime += time - currentProcess.arrt - currentProcess.burstt;

      while (it < n && v[it].arrt <= time)
      {
        q.push(v[it]);
        it++;
      }
    }
  }

  printf("%0.2f %0.2f\n", (float)totalWaitingTime / (float)n, (float)totalTurnAroundTime / (float)n);

  return completion;
}


int main()
{

 int n, tq;
 cin>>n>>tq;

 vector <processes> v;
 queue <processes> q;

 for(int i = 0; i<n ; i++)
 {
   processes process;
   cin>>process.arrt>>process.burstt;
   process.newburstt = process.burstt;
   process.pid = i+1;
   v.push_back(process);
 }

 sort(v.begin(),v.end(),compare);

 vector<processes> completion = roundRobin(n,tq,v,q);

 for(int i = 0; i<n ; i++)
   cout<<"P"<<completion[i].pid<<" ";
 cout<<endl;

return 0;
}
