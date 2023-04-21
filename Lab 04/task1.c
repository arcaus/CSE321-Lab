

#include <stdio.h>


int main()
{
    int at[20], bt[20], temp[20];
    int i, smallest, count = 0, time, tpd;
    double wt = 0, tat = 0, end;
    int ct[20], turnaround[20], waiting[20];
    printf("Number of Processes: ");
    scanf("%d", &tpd);

    for (i = 0; i < tpd; i++)
    {
        printf("\nProcess Details of P%d: ", i + 1);
        printf("\nArrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    bt[9] = 999999;
    for (time = 0; count != tpd; time++)
    {
        smallest = 9;
        for (i = 0; i < tpd; i++)
        {
            if (at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
            {
                smallest = i;
            }
        }
        bt[smallest]--;
        if (bt[smallest] == 0)
        {
            count++;
            end = time + 1;
            ct[smallest] = end;
            wt = end - at[smallest] - temp[smallest];
            tat = end - at[smallest];
            waiting[smallest] = wt;
            turnaround[smallest] = tat;
        }
    }
    for (i = 0; i < tpd; i++)
    {
        printf("\nProcess %d:\tCompletion Time = %d\tTurnaround Time = %d\tWaiting Time = %d", i + 1, ct[i], waiting[i], turnaround[i]);
    }

    return 0;
}
