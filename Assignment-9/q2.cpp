#include <bits/stdc++.h>
using namespace std;

//most recently used page replacement: prints frame contents at each step and finally returns number of page faults
int mru(int n, vector<int> &seq, int frameCount)
{
    cout<<"MRU"<<endl;
    for(int i=1;i<=frameCount;i++)
    {
        cout<<"F"<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<frameCount;i++)
    {
        cout<<"X  ";
    }
    cout<<"at time 0"<<endl;
    int frames[frameCount];
    memset(frames,-1,sizeof(frames));
    //doubly linked list to store the current pages in the frames: first element (front) will be the least recently used page and last will be the most recently used
    list<int>li;
    unordered_map<int, list<int>::iterator>mpPageToList;    //map from page number to position in the list
    unordered_map<int, int> mpPageToFrame;                  //map from page number to frame number in which it is placed
    int curframe=0;
    int pageFaults=0;
    for(int i=0;i<n;i++)
    {
       int curpage= seq[i];
       if(mpPageToFrame.find(curpage)!=mpPageToFrame.end()) //page already present in some frame
       {
           //remove the page from the list and insert at the end of the list to make it most recently used
            auto it=mpPageToList[curpage];
            li.erase(it);
            li.push_back(curpage);
            it=li.end();
            it--;
            mpPageToList[curpage]= it;
       }
       else if(frames[curframe]==-1)                        //empty frame available so place the page into it
       {
           //place the page into the curframe
           frames[curframe]=curpage;
           mpPageToFrame[curpage]=curframe;
           //push the page at the end of the list
           li.push_back(curpage);
           auto it=li.end();
           it--;
           mpPageToList[curpage]= it;
           pageFaults++;
           curframe=(curframe+1)%frameCount;
       }
       else                                                 //no empty frame so remove the most recently used page
       {
            auto it=li.end();
            it--;                                           //end of the list is the most recently used page
            int mrupage=*it;
            curframe=mpPageToFrame[mrupage];
            //remove the most recently used page
            li.erase(it);
            mpPageToFrame.erase(mrupage);
            mpPageToList.erase(mrupage);
            //insert the current page at the end of the list
            li.push_back(curpage);
            it=li.end();
            it--;
            mpPageToList[curpage]= it;
            mpPageToFrame[curpage]=curframe;
            //place the current page in the curframe
            frames[curframe]=curpage;
            pageFaults++;
       }
       for(int i=0;i<frameCount;i++)                        //print the contents of the frames
       {
           if(frames[i]==-1)
            cout<<'X'<<"  ";
           else
            cout<<frames[i]<<"  ";
       }
       cout<<"at time "<<i+1<<endl;

    }
    return pageFaults;
}

int main()
{
   int frameCount;                              //number of frames
   cin>>frameCount;
   string s;                                    //reference string
   getline(cin,s);
   getline(cin,s);
   stringstream ss;
   ss<<s;
   vector<int>seq;                              //reference string converted to sequence of integers
   int num;
   while(ss>>num)
   {
       seq.push_back(num);
   }
   int n=seq.size();
   int mfault=mru(n,seq,frameCount);            //call function and print the page faults
   cout<<"#Page faults: "<<mfault<<endl;

 return 0;
}


