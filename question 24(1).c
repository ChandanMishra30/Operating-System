#include<stdio.h>
#include<conio.h>


struct process
{   
    char p_name;
    int arrival_t,burst_t,comp_t,waiting_t,turnaround_t,priority,rt;
    int status;
}proc_queue[10];

void fixed_Priority_Scheduling()
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
    //fixed_Priority_Scheduling();
}