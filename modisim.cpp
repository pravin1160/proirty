#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int brust_t[10],pro[10],wait_t[10],turn_at[10],pri[10],i,j,n,total=0,pos,temp;
    float avg_wait_t,avg_turn_at;
    cout<<"Enter Total Number of Process:";
    cin>>n;
 
    cout<<"Enter Burst Time and Priority";
    for(i=0;i<n;i++)
    {
        cout<<"\nPro["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>brust_t[i];
        cout<<"Priority:";
        cin>>pri[i];
        pro[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pri[j]<pri[pos])
                pos=j;
        }
 
        temp=pri[i];
        pri[i]=pri[pos];
        pri[pos]=temp;
 
        temp=brust_t[i];
        brust_t[i]=brust_t[pos];
        brust_t[pos]=temp;
 
        temp=pro[i];
        pro[i]=pro[pos];
        pro[pos]=temp;
    }
 
    wait_t[0]=0;            //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wait_t[i]=0;
        for(j=0;j<i;j++)
            wait_t[i]+=brust_t[j];
 
        total+=wait_t[i];
    }
 
    avg_wait_t=total/n;      //average waiting time
    total=0;
 
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        turn_at[i]=brust_t[i]+wait_t[i];     //calculate turnaround time
        total+=turn_at[i];
        cout<<"\nP["<<pro[i]<<"]\t\t  "<<brust_t[i]<<"\t\t    "<<wait_t[i]<<"\t\t\t"<<turn_at[i];
    }
 
    avg_turn_at=total/n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time="<<avg_wait_t;
    cout<<"\nAverage Turnaround Time="<<avg_turn_at;
 
    return 0;
}
