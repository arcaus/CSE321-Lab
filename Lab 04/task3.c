// Program written by: Iftekhar Turja

#include <stdio.h>

/*Given the list of processes, their CPU burst times, arrival times and time quantum and implement priority scheduling algorithm, on the processes. Finally compute and print the completion Time(CT) for each process, and their Turnaround Time(TAT), and Waiting Time(WT).*/

// priority scheduling algorithm
int main()
{
    int at[20], wt[20], tat[20], bt[20], pri[20], ct[20];
    int number, temp[20], t, count = 0, small;
    float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT;
    printf("Enter the number of Processes: ");
    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        printf("Enter Arrival Time of Process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
        printf("Enter Priority of Process %d: ", i + 1);
        scanf("%d", &pri[i]);
    }

    pri[9] = 999999;

    for (t = 0; count != number; t++)
    {
        small = 9;
        for (int i = 0; i < number; i++)
        {
            if (pri[small] > pri[i] && at[i] <= t && bt[i] > 0)
            {
                small = i;
            }
        }

        bt[small] = bt[small] - 1;

        if (bt[small] == 0)
        {

            count++;
            wt[small] = t + 1 - at[small] - temp[small];
            tat[small] = t + 1 - at[small];

            ct[small] = t + 1;
        }
    }

    for (int i = 0; i < number; i++)
    {
        printf("\nProcess %d:\tCompletion Time = %d\tTurnaround Time = %d\tWaiting Time = %d", i + 1, ct[i], wt[i], tat[i]);
    }

    return 0;
}
