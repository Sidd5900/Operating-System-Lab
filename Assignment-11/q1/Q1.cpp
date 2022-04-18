#include<bits/stdc++.h>
using namespace std;
int cylinders=200;
int start=100;

int fcfs(vector<int> &workq, int n)
{
    int curhead=start;
    int movement=0;
    vector<int> head;
    head.push_back(start);
    for(int i=0;i<n;i++)
    {
        movement+=abs(workq[i]-curhead);
        curhead=workq[i];
        head.push_back(curhead);
    }
    ofstream outfile("fcfs.dat");
    for (int i = 0; i < head.size(); i++)
    {
        outfile <<i<< " " << head[i] << endl;
    }
    outfile.close();
    return movement;
}

int scan(vector<int> workq, int n)
{
    int curhead=start;
    int movement=0;
    vector<int> head;
    head.push_back(start);
    sort(workq.begin(), workq.end());
    int idx=lower_bound(workq.begin(), workq.end(), curhead)-workq.begin(); //index of first element >= start head pointer
    for(int i=idx;i<n;i++)
    {
        movement+=abs(workq[i]-curhead);
        curhead=workq[i];
        head.push_back(curhead);
    }
    if(idx==0)  //all requests completed
    {
        return movement;
    }
    movement+= 199-curhead;
    curhead=199;
    head.push_back(curhead);
    for(int i=idx-1;i>=0;i--)
    {
        movement+=abs(workq[i]-curhead);
        curhead=workq[i];
        head.push_back(curhead);
    }

    ofstream outfile("scan.dat");
    for (int i = 0; i < head.size(); i++)
    {
        outfile <<i<< " " << head[i] << endl;
    }
    outfile.close();
    return movement;
}


int cscan(vector<int> workq, int n)
{
    int curhead=start;
    int movement=0;
    vector<int> head;
    head.push_back(start);
    sort(workq.begin(), workq.end());
    int idx=lower_bound(workq.begin(), workq.end(), curhead)-workq.begin(); //index of first element >= start head pointer
    for(int i=idx;i<n;i++)
    {
        movement+=abs(workq[i]-curhead);
        curhead=workq[i];
        head.push_back(curhead);
    }
    if(idx==0)  //all requests completed
    {
        return movement;
    }
    movement+= 199-curhead;
    curhead=199;
    head.push_back(curhead);
    movement+=199-0;
    curhead=0;
    head.push_back(curhead);
    for(int i=0;i<idx;i++)
    {
        movement+=abs(workq[i]-curhead);
        curhead=workq[i];
        head.push_back(curhead);
    }

    ofstream outfile("cscan.dat");
    for (int i = 0; i < head.size(); i++)
    {
        outfile <<i<< " " << head[i] << endl;
    }
    outfile.close();
    return movement;
}


int sstf(vector<int> workq, int n)
{
    int curhead=start;
    int movement=0;
    vector<int> head;
    head.push_back(start);
    multiset<int>st;
    for(int i=0;i<n;i++)
    {
        st.insert(workq[i]);
    }
    while(!st.empty())
    {
        auto it1=st.lower_bound(curhead);
        if(st.size()==1)
        {
            int diff=abs(curhead-(*st.begin()));
            movement+=diff;
            curhead=*st.begin();
            head.push_back(curhead);
            //cout<<"diff "<<diff<<endl;
            st.erase(st.begin());
        }
        else if(it1==st.begin())
        {
            int diff1=abs(curhead-(*it1));
            //cout<<"diff1 "<<diff1<<endl;
            movement+=diff1;
            curhead=*it1;
            head.push_back(curhead);
            st.erase(it1);
        }
        else if(it1==st.end())
        {
            it1--;
            auto it2=it1;
            int diff2=abs(curhead-(*it2));
            //cout<<"diff2 "<<diff2<<endl;
            movement+=diff2;
            curhead=*it2;
            head.push_back(curhead);
            st.erase(it2);
        }
        else
        {
            it1--;
            auto it2=it1;
            it1++;
            int diff1=abs(curhead-(*it1));
            int diff2=abs(curhead-(*it2));
            if(diff1<=diff2)
            {
                //cout<<"diff1 "<<diff1<<endl;
                movement+=diff1;
                curhead=*it1;
                head.push_back(curhead);
                st.erase(it1);
            }
            else
            {
                //cout<<"diff2 "<<diff2<<endl;
                movement+=diff2;
                curhead=*it2;
                head.push_back(curhead);
                st.erase(it2);
            }
        }

    }
    ofstream outfile("sstf.dat");
    for (int i = 0; i < head.size(); i++)
    {
        outfile <<i<< " " << head[i] << endl;
    }
    outfile.close();
    return movement;

}


int main()
{
    int n;
    cout<<"Enter the number of requests:"<<endl;
    cin>>n;
    vector<int> workq(n);
    cout<<"Enter the requests:"<<endl;
    for(int i=0;i<n;i++)
        cin>>workq[i];
    int thmfcfs=fcfs(workq,n);
    int thmscan=scan(workq,n);
    int thmcscan=cscan(workq,n);
    int thmsstf=sstf(workq,n);
    cout<<"Total head movement for fcfs = "<<thmfcfs<<endl;
    cout<<"Total head movement for scan = "<<thmscan<<endl;
    cout<<"Total head movement for cscan = "<<thmcscan<<endl;
    cout<<"Total head movement for sstf = "<<thmsstf<<endl;

    cout<<"Total seek time for fcfs (in milliseconds)= "<<thmfcfs*5<<endl;
    cout<<"Total seek time for scan = "<<thmscan*5<<endl;
    cout<<"Total seek time for cscan = "<<thmcscan*5<<endl;
    cout<<"Total seek time for sstf = "<<thmsstf*5<<endl;

    vector<pair<int,int>>order;
    order.push_back({thmfcfs,0});
    order.push_back({thmscan,1});
    order.push_back({thmcscan,2});
    order.push_back({thmsstf,3});

    sort(order.begin(), order.end());
    cout<<"Order of algoritms in ascending order of seek time:"<<endl;
    for(int i=0;i<4;i++)
    {
        int x= order[i].second;
        if(x==0)
            cout<<"FCFS"<<" ";
        else if(x==1)
            cout<<"SCAN"<<" ";
        else if(x==2)
            cout<<"CSCAN"<<" ";
        else if(x==3)
            cout<<"SSTF"<<" ";
    }

    return 0;
}
