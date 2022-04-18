#include<bits/stdc++.h>
using namespace std;
const int N=10000005;           //maximum number of frames

bool isempty[N];                //to check which frame number is empty (not allocated by any page)
unordered_map<int,int> mpPageToFrame;     //map from page number to frame number
int p,v,f;
int curpage;    //next page number to be allocated

//convert from logical address to physical address
int translate(int logadd)
{
    int pagenumber= (logadd>>f);
    int mask = (1<<f)-1;
    int pageoffset= (mask&logadd);
    int frameoffset= pageoffset;
    if(mpPageToFrame.find(pagenumber)!=mpPageToFrame.end()) //page present in page table
    {
        int framenumber=mpPageToFrame[pagenumber];
        int phyadd= (framenumber<<f) + frameoffset;
        return phyadd;
    }
    return -1;      //page not present in page table
}

//allocate pages to frames of size = psize
void allocate(int psize)
{
    int framesize= 1<<f;
    int numframes= psize/framesize;     //no of frames to be allocated
    int totframes= (1<<(p-f));          //total no of frames available
    int framesallocated=0;              //number of frames allocated so far
    vector<int> frames;                 //to store the list of frame numbers allocated
    for(int i=0;i<totframes;i++)
    {
        if(isempty[i])
        {
            mpPageToFrame[curpage]=i;
            curpage++;
            isempty[i]=0;
            frames.push_back(i);
            framesallocated++;
        }
        if(framesallocated==numframes)
            break;
    }
    if(framesallocated==numframes)      //all pages allocated
    {
        cout<<psize<<" bytes has been allocated in frame numbers ";
        for(auto fr: frames)
            cout<<fr<<" ";
        cout<<endl;
    }
    else    //some pages as no space was left in the memory
    {
        int sizeallocated= framesize * (frames.size());
        cout<<sizeallocated<<" bytes has been allocated in frame numbers ";
        //printing only the allocated frames
        for(auto fr: frames)
            cout<<fr<<" ";
        cout<<endl;
    }

}

int main()
{
    cin>>p>>v>>f;
    int n;      //no of pairs to be taken as input for which corresponding frames cannot be allocated
    cin>>n;
    memset(isempty,true,sizeof(isempty));
    int l,r;
    for(int i=0;i<n;i++)
    {
        cin>>l>>r;
        for(int j=l;j<=r;j++)
        {
            isempty[j]=0;
        }
    }
    char ch;
    int x;
    while(1)    //take infinite number of queries
    {
      cin>>ch>>x;
      if(ch=='a')
      {
          allocate(x);
      }
      else if(ch=='t')
      {
          int phyadd= translate(x);
          if(phyadd==-1)
            cout<<"invalid page number"<<endl;
          else
            cout<<"the physical address is- "<<phyadd<<endl;
      }
      else if(ch=='d')
      {
          if(mpPageToFrame.find(x)!=mpPageToFrame.end())    //page found
          {
              int framenumber=mpPageToFrame[x];
              mpPageToFrame.erase(x);
              isempty[framenumber]=1;
              cout<<"page no "<<x<<" has been deleted"<<endl;
          }
          else
            cout<<"no page with page number "<<x<<endl;
      }
    }


 return 0;
}
