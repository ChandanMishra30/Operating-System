#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

struct process
{   
    char p_name;
    int arrival_t,burst_t,comp_t,waiting_t,turnaround_t,priority,rt;
    int status;
}proc_queue[10];

/*bool comp(struct process a,struct process b) 
{ 
if(a.arrival_t == b.arrival_t) 
{ 
return a.priority<b.priority; 
} 
else
{ 
    return a.arrival_t<b.arrival_t; 
} 
}*/
void get_wt_time(int wt[],int lim) 
{ 
int service[50],i; 
service[0]=0; 
wt[0]=0; 
for(i=1;i<lim;i++) 
{ 
service[i]=proc_queue[i-1].burst_t+service[i-1]; 
  
wt[i]=service[i]-proc_queue[i].arrival_t+1;
      
    if(wt[i]<0) 
    { 
    wt[i]=0; 
    } 
} 
} 
void get_tat_time(int tat[],int wt[],int lim) 
{ 
int i;
for(i=0;i<lim;i++) 
{ 
    tat[i]=proc_queue[i].burst_t+wt[i]; 
} 
} 

void fixed_Priority_Scheduling(int limit2)
{

}

void main()
{
    int limit,i,time_quantum,remain,count,time,flag=0,wait_time=0,turnaround_time=0;
    char c;
    printf("Enter Total Number Of Processes: ");
    scanf("%d",&limit);
    remain=limit;
    for(i=0,c='A';i<limit;i++,c++)
    {
        proc_queue[i].p_name=c;
        printf("Enter The Details For Process [%C]:\n",proc_queue[i].p_name);
        printf("Enter Arrival Time:\t");
        scanf("%d",&proc_queue[i].arrival_t);
        printf("Enter Burst Time:\t");
        scanf("%d",&proc_queue[i].burst_t);
        proc_queue[i].rt=proc_queue[i].burst_t;
        printf("Enter Priority (0 is the highest Priority):\t");
        scanf("%d",&proc_queue[i].priority);
        proc_queue[i].status=0;
    }
    //system("cls");
    printf("\t\t\t\t\tLevel 1 : Fixed Priority Preemptive Scheduling\n\t\t\t\t================================================================\n\n\n ");
    //sort(proc_queue,proc_queue+limit,comp);
    fixed_Priority_Scheduling(limit);
    printf("\t\t\t\t\t\tLevel 2 : Round Robin Scheduling\n\t\t\t\t================================================================\n\n\n ");
    printf("Enter Time Quantum:");
    scanf("%d",&time_quantum);
    printf("\n\nProcess\t|Arrival Time|Burst Time|Turnaround Time|Waiting Time|Completion Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(proc_queue[count].rt<=time_quantum && proc_queue[count].rt>0) 
    { 
      time+=proc_queue[count].rt; 
      proc_queue[count].rt=0; 
      flag=1; 
    } 
    else if(proc_queue[count].rt>0) 
    { 
      proc_queue[count].rt-=time_quantum; 
      time+=time_quantum; 
    } 
    if(proc_queue[count].rt==0 && flag==1) 
    { 
      remain--; 
      int waiting_time=time-proc_queue[count].arrival_t-proc_queue[count].burst_t;
      if(waiting_time<0)
      {
        waiting_time=0;
      }
      printf("P[%c]\t|\t%d    |\t%d\t|\t%d\t|\t%d    |\t%d\n",proc_queue[count].p_name,proc_queue[count].arrival_t,proc_queue[count].burst_t,time-proc_queue[count].arrival_t,waiting_time,proc_queue[count].arrival_t+time-proc_queue[count].arrival_t); 
      wait_time+=waiting_time; 
      turnaround_time+=time-proc_queue[count].arrival_t; 
      flag=0; 
    } 
    if(count==limit-1) 
      count=0; 
    else if(proc_queue[count+1].arrival_t<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/limit); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/limit); 
}