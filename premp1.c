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
    AT_Sorting;
    proc_queue[9].priority=-9999;
    printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
    for(t = proc_queue[0].arrival_t;t<burst_t;)
    {
        largest = 9;
        for(i=0;i<limit;i++)
        {
            if(proc_queue[i].arrival_t <= t && proc_queue[i].status !=1 && proc_queue[i].priority > proc_queue[largest].priority )
            {
                largest = i;
            }
        }
            t=t + proc_queue[largest].burst_t;
            proc_queue[largest].comp_t=t;
            proc_queue[largest].waiting_t=proc_queue[largest].comp_t - proc_queue[largest].arrival_t - proc_queue[largest].burst_t ;
            proc_queue[largest].turnaround_t=proc_queue[largest].comp_t - proc_queue[largest].arrival_t;
            proc_queue[largest].status=1;
            wait_t = wait_t + proc_queue[largest].waiting_t;
            turnaround_t=turnaround_t+proc_queue[largest].turnaround_t;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",proc_queue[largest].p_name,proc_queue[largest].arrival_t,proc_queue[largest].burst_t,proc_queue[largest].priority,proc_queue[largest].waiting_t);
        }
        avg_wt=wait_t / limit;
        avg_tt=turnaround_t/limit;
        printf("\n\nAverage Waiting Time Is: \t%f\n",avg_wt);
        printf("Average Turnaround Time Is: \t%f\n",avg_tt);
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

