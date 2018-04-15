#include<iostream>
#include<stdlib.h>
using namespace std;
class process
{public:
int pid;
int bt;
int wt;
int tat;
int size;
int tstart, tend;
int ticket[100];
void putticket()
{
int j=0;
for(int i=tstart;i<tend;i++)
{ticket[j]=i;
j++;
}
}
void showticket()
{int j=0;
for(int i=tstart;i<tend;i++)
{cout<<ticket[j]<<" ";
j++;
}
}
int searchticket(int q)
{int j=0,c=0;
for(int i=tstart;i<tend;i++)
{if(ticket[j]==q)
{return 1;
}
j++;
}return 0;
}
};
 int main()
{int n;
int sze;
cout<<"Enter the Number of Processes ";
cin>>n;
int ts=0,te;
class process p[n],c[n];
for(int i=0;i<n;i++)
{cout<<"Enter the process id for "<<i+1<<" process  ";
cin>>p[i].pid;
cout<<"Enter the Burst Time for "<<i+1<<" process  ";
cin>>p[i].bt;
c[i].bt=p[i].bt;
p[i].wt=0;
cout<<"Enter  the ending number of  ticket for "<<i+1<<" process ranging from from  "<<ts<<" to 200  ";
cin>>te;
p[i].tstart=ts;
p[i].tend=te;
sze=te-ts;
p[i].size=sze;
p[i].putticket();
ts=te;
}
for(int i=0;i<n;i++)
{
cout<<"Process id for "<<i+1<<" process is  "<<p[i].pid<<'\n';
cout<<"Burst Time for "<<i+1<<" process is  "<<p[i].bt<<'\n';
cout<<"Number of tickets "<<i+1<<" process have  "<<p[i].size<<'\n';
cout<<"Range of tickets for "<<i+1<<" process is"<<'\n';
p[i].showticket(); 
cout<<'\n';

}
int x,l,tslice;

cout<<"Enter the Time Slice ";
cin>>tslice;

for(int k=0;k<15;k++)
{x=(rand()%25);
cout<<" The random number generated is "<<x<<'\n';
for(int i=0;i<n;i++)
{

l=p[i].searchticket(x);
if(l==1)
{if(p[i].bt<=0)
{cout<<"Process with Process id "<<p[i].pid<<" is already executed completely"<<'\n';
}
else
{p[i].bt=p[i].bt-tslice;
if(p[i].bt<0)
cout<<"Remaining burst time for process with process id "<<p[i].pid<<" is "<<0;
else
cout<<"Remaining burst time for process with process id "<<p[i].pid<<" is "<<p[i].bt<<'\n';
}

}
if(l==0&&p[i].bt>0)
{p[i].wt+=tslice;
}
}
}
for(int i=0;i<n;i++)
{cout<<"Process id for "<<i+1<<" process is  "<<p[i].pid<<'\n';
cout<<"Burst Time for "<<i+1<<" process is  "<<c[i].bt<<'\n';
cout<<"Waiting Time for "<<i+1<<" process is  "<<p[i].wt<<'\n';
cout<<"Turn Around Time for "<<i+1<<" process is  "<<p[i].wt+c[i].bt<<'\n';
}
}
