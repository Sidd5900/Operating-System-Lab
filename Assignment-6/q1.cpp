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
};

struct mycomp{
bool operator()(struct Process &p1, struct Process &p2)
{
    if(p1.arrt == p2.arrt)
    {
        return(p1.pid > p2.pid);
    }
    else
        return(p1.arrt > p2.arrt);
}
};

priority_queue<struct Process,vector<struct Process>,mycomp> pq;//opp(first by desc, second by asc)
vector<int> order;

void fcfs(vector<struct Process> &proc)
{
    int curtime = 0;
    while(!pq.empty())
    {
        struct Process curproc = pq.top();
        pq.pop();
        int pid = curproc.pid;
        int arrt = curproc.arrt;
        int burstt = curproc.burstt;
        curtime= max(curtime,arrt);
        //cout<<pid<<" "<<arrt<<" "<<burstt<<" "<<curtime<<endl;
        proc[pid].compt = curtime + burstt;
        proc[pid].turnt = proc[pid].compt - proc[pid].arrt;
        proc[pid].waitt = proc[pid].turnt - proc[pid].burstt;
        //cout<<proc[pid].compt<<" "<<proc[pid].turnt<<" "<<proc[pid].waitt<<endl;
        curtime = curtime + burstt;
        order.push_back(pid);
    }
}


int main()
{
    int n;
    cin>>n;
    int a,b;
    vector<struct Process> proc(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        proc[i].pid = i;
        proc[i].arrt = a;
        proc[i].burstt = b;
        pq.push(proc[i]);
    }

    fcfs(proc);

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
