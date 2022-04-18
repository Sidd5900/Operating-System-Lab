#include<bits/stdc++.h>

using namespace std;

//maximum processes or resources
const int maxm = 21;

int allocation[maxm][maxm]; //resource instances already allocated to each process
int maxneed[maxm][maxm];    //maximum resource instances needed for each process
int need[maxm][maxm];       //remaining resource instances needed for each process
vector<int> safeseq;        //stores the safe sequence
bool issafe;                //check if a safe sequence exists

//bankers algorithm to generate all possible safe sequences or if deadlock exists
void bankersAlgo(int n, int m, bool isCompleted[], int available[], int cnt)
{
    //when all processes are completed print the sequence
    if(cnt == n)    //cnt stores the number of processes completed
    {
        if(!issafe)
        {
            issafe = true;
            cout<<"Safe sequence exists:"<<endl;
        }
        //print the safe sequence
        for(auto process: safeseq)
            cout<<"P"<<process<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        //allocate resources to Process i if it is not completed and remaining resources needed can be satisfied by available resources
        if(!isCompleted[i])
        {
            int flag=0;
            for(int j=0;j<m;j++)
            {
                if(need[i][j] > available[j])   //cannot satisfy the need
                {
                    flag = 1;
                    break;
                }
            }
            //give resources to Process i as resources needed can be satisfied
            if(flag==0)
            {
                //push to safe sequence, mark as completed and free up the resources
                safeseq.push_back(i);
                isCompleted[i] = true;
                for(int j=0;j<m;j++)
                    available[j] = available[j] + allocation[i][j];

                //recursive call
                bankersAlgo(n,m,isCompleted,available,cnt+1);

                //backtrack
                safeseq.pop_back();
                isCompleted[i] = false;
                for(int j=0;j<m;j++)
                    available[j] = available[j] - allocation[i][j];
            }
        }
    }
}


int main()
{
    int n,m;
    cout<<"Enter the number of processes"<<endl;
    cin>>n;
    cout<<"Enter the number of resources"<<endl;
    cin>>m;

    cout<<"Enter the allocation matrix (resources already allocated to each process)"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>allocation[i][j];

    cout<<"Enter the max matrix (maximum resources needed for each process)"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>maxneed[i][j];
            //computing need matrix
            need[i][j] = maxneed[i][j] - allocation[i][j];
        }
    }

    int available[maxm];    //available resource instances for each resource
    cout<<"Enter the available resources (number of instances of each resource available)"<<endl;
    for(int i=0;i<m;i++)
        cin>>available[i];

    bool isCompleted[n];    //to check which processes are already completed
    memset(isCompleted, false, sizeof(isCompleted));    //initially all false (none is completed)

    //calling bankersAlgo function to generate safe sequence is possible
    bankersAlgo(n,m,isCompleted, available, 0);

    //if no safe sequence found
    if(!issafe)
        cout<<"Deadlock detected (No safe sequence possible)"<<endl;
    return 0;
}
