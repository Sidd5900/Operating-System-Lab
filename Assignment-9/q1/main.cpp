#include<bits/stdc++.h>
using namespace std;

//first in first out page replacement: prints frame contents at each step and finally returns number of page faults
int fifo(int n, vector<int> &seq, int frameCount)
{
    cout<<"FIFO"<<endl;
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
    int frames[frameCount];                 //frames[i] store the page in the ith frame
    memset(frames,-1,sizeof(frames));       //initialize frames with -1 which indicates empty
    unordered_set<int> st;                  //set to store the pages present in the frames at the current time
    int curframe=0;                         //frame in which the current page needs to be placed
    int pageFaults=0;                       //stores count of page faults
    for(int i=0;i<n;i++)                    //traverse the reference string
    {
       int curpage= seq[i];                 //current page to be placed in some frame
       if(st.find(curpage)!=st.end())       //page already present in some frame so do nothing
       {
            ;
       }
       else if(frames[curframe]==-1)        //empty frame available so place the page in the frame
       {
           frames[curframe]=curpage;
           st.insert(curpage);
           pageFaults++;
           curframe=(curframe+1)%frameCount;
       }
       else                                 //no empty frame so swap out the page in the curframe and place the current page into it
       {
            st.erase(frames[curframe]);
            frames[curframe]=curpage;
            st.insert(curpage);
            pageFaults++;
            curframe=(curframe+1)%frameCount;
       }
       for(int i=0;i<frameCount;i++)        //print the contents of the frames
       {
           if(frames[i]==-1)
            cout<<'X'<<"  ";
           else
            cout<<frames[i]<<"  ";
       }
       cout<<"at time "<<i+1<<endl;

    }
    return pageFaults;                      //return total page faults
}


//least recently used page replacement: prints frame contents at each step and finally returns number of page faults
int lru(int n, vector<int> &seq, int frameCount)
{
    cout<<"LRU"<<endl;
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
       else                                                 //no empty frame so remove the least recently used page
       {
            auto it=li.begin();                             //beginning of the list is the least recently used page
            int lrupage=*it;                                //least recently used page
            curframe=mpPageToFrame[lrupage];
            //remove the least recently used page
            li.erase(it);
            mpPageToFrame.erase(lrupage);
            mpPageToList.erase(lrupage);
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


//optimal page replacement: prints frame contents at each step and finally returns number of page faults
int opt(int n, vector<int> &seq, int frameCount)
{
    cout<<"OPTIMAL"<<endl;
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
    unordered_map<int,int>mpPageToFrame;                        //map from page number to frame in which its is stored
    int curframe=0;
    int pageFaults=0;
    for(int i=0;i<n;i++)
    {
       int curpage= seq[i];
       if(mpPageToFrame.find(curpage)!=mpPageToFrame.end())     //page already present in some frame
       {
            ;
       }
       else if(frames[curframe]==-1)                            //empty frame slot available so place the page in the curframe
       {
           frames[curframe]=curpage;
           mpPageToFrame[curpage]=curframe;
           pageFaults++;
           curframe=(curframe+1)%frameCount;
       }
       else                                                     //no empty frame                     //
       {
            unordered_map<int,int> mpPageToNextIndex;           //map from page number to the position of its next occurrence from current index
            int foundPages=0;                                   //number of pages found to the right of the current index which are also in some frame
            for(int j=i+1;j<n;j++)                              //traverse the right indices
            {
                //if page at the index present in some frame and encountered first time
                if(mpPageToFrame.find(seq[j])!=mpPageToFrame.end() && mpPageToNextIndex.find(seq[j])==mpPageToNextIndex.end())
                {
                    foundPages++;
                    mpPageToNextIndex[seq[j]]=j;
                    if(foundPages==frameCount)                  //Page number seq[j] will be the last page used among the pages in the frames
                    {
                        //remove the found page and insert the current page
                        curframe= mpPageToFrame[seq[j]];
                        frames[curframe]=curpage;
                        mpPageToFrame[curpage]=curframe;
                        mpPageToFrame.erase(seq[j]);
                        break;
                    }
                }
            }

            if(foundPages!=frameCount)                          //some page exists in some frame which do not occur anytime in the future
            {
                for(int j=0;j<frameCount;j++)
                {
                    //find any one page that is not required in future
                    int page= frames[j];
                    if(mpPageToNextIndex.find(page)==mpPageToNextIndex.end())   //we got the page not required anytime in future
                    {
                        //remove the found page and insert the current page
                        curframe= mpPageToFrame[page];
                        frames[curframe]=curpage;
                        mpPageToFrame[curpage]=curframe;
                        mpPageToFrame.erase(page);
                        break;
                    }
                }
            }
            pageFaults++;
       }
       for(int i=0;i<frameCount;i++)                                //print the contents of the frames
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
   int frameCount;                                                  //number of frames
   cin>>frameCount;
   string s;                                                        //reference string
   getline(cin,s);                                                  //first getline for newline
   getline(cin,s);
   stringstream ss;                                                 //to get integers from the given string
   ss<<s;
   vector<int>seq;                                                  //will store the corresponding integers from the string
   int num;
   while(ss>>num)
   {
       seq.push_back(num);
   }
   int n=seq.size();                                                //size of sequence (reference string)
   //call functions for each of the algorithms
   int ffault=fifo(n,seq,frameCount);
   cout<<"#Page faults: "<<ffault<<endl;
   cout<<endl;
   int lfault=lru(n,seq,frameCount);
   cout<<"#Page faults: "<<lfault<<endl;
   cout<<endl;
   int ofault=opt(n,seq,frameCount);
   cout<<"#Page faults: "<<ofault<<endl;
   cout<<endl;
   cout<<"Best Page Replacement Algorithm: ";
   //find the least page fault
   if(ofault<=ffault && ofault<=lfault)
    cout<<"OPTIMAL"<<endl;
   else if(lfault<=ffault && lfault<=ofault)
    cout<<"LRU"<<endl;
   else
    cout<<"FIFO"<<endl;

 return 0;
}
