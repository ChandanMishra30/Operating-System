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
        proc_queue[i].processes=c;
        printf("\nEnter Details for Process [%C]:\n",proc_queue[i].processes);
        printf("\nEnter Arrival Time:\t");

    }
}
void AT_Sorting()
{
    struct process temp;
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

