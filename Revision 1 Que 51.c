#include<stdio.h>

struct processes
{
    char p_name;
    int arrival_t,burst_t,comp_t,waiting_t,turnaround_t,priority;
    int status;
}proc_queue[10];

int limit;
void AT_Sorting();
void main()
{
    int i,t,burst_t=0 , largest;
    char c;
    float wait_t = 0,turnaround_t = 0, avg_wt,avg_tt;
    scanf("%d",&limit);
    for(i=0 , c ='A' ; i<limit;i++,c++)
    {
        proc_queue[i].p_name=c;
        printf("\nEnter Details for Process [%C]:\n",proc_queue[i].p_name);
        printf("Enter Arrival Time:\t");
        scanf("%d",&proc_queue[i].arrival_t);
        printf("Enter Burst Time:\t");
        scanf("%d",&proc_queue[i].burst_t);
        printf("Enter Priority : \t");
        scanf("%d",proc_queue[i].priority);
        proc_queue[i].status=0;
        burst_t=burst_t+ proc_queue[i].burst_t;
    }
    
void AT_Sorting()
{
    struct processes temp;
    int i,j;
    for(i=0;i<limit -1 ; i++)
    {
        for(j=i+1;j<limit;j++)
        {
            if(proc_queue[i].arrival_t>proc_queue[j].arrival_t)
            {
                temp = proc_queue[i];
                proc_queue[i]=proc_queue[j];
                proc_queue[j]=temp;
            }
        }
    }
}

