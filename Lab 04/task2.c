
#include <stdio.h>


// round robin scheduling algorithm

int main()
{
    int number, i, quantam, bt[10], rbt[10], wt[10], trt[10], ct[10];
    printf("Number of processes: ");
    scanf("%d", &number);

    for (i = 0; i < number; i++)
    {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    printf("Enter the quantum: ");
    scanf("%d", &quantam);
    // waiting time
    for (i = 0; i < number; i++)
    {
        rbt[i] = bt[i];
    }
    int time = 0;
    while (1)
    {
        int flag = 0;
        for (i = 0; i < number; i++)
        {
            if (rbt[i] > 0)
            {
                flag = 1;
                if (rbt[i] > quantam)
                {
                    time = time + quantam;
                    rbt[i] -= quantam;
                    ct[i] = time;
                }
                else
                {
                    time = time + rbt[i];
                    wt[i] = time - bt[i];

                    ct[i] = time;
                    rbt[i] = 0;
                }
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    // turnaround time
    for (i = 0; i < number; i++)
    {
        trt[i] = bt[i] + wt[i];
    }
    // printing the result
    for (i = 0; i < number; i++)
    {
        printf("\nProcess %d:\tCompletion Time = %d\tTurnaround Time = %d\tWaiting Time= %d", i + 1, ct[i], wt[i], trt[i]);
    }

    return 0;
}
