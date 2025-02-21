#include <stdio.h>

int main()
{
    int processes;
    printf("Enter the no of processes: ");
    scanf("%d", &processes);

    int pid[processes], at[processes], bt[processes], ct[processes], tat[processes], wt[processes];
    float avgWT, avgTAT;
    for (int i = 0; i < processes; i++)
    {
        printf("Enter processs id: ");
        scanf("%d", &pid[i]);

        printf("Enter arrival time of processs %d: ", i);
        scanf("%d", &at[i]);

        printf("Enter burst time of processs %d: ", i);
        scanf("%d", &bt[i]);
    }

    int temp;

    for (int i = 0; i < processes - 1; i++)
    {
        for (int j = 0; j < processes - 1 - i; j++)
        {
            if (at[j] > at[j + 1])
            {
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];
    wt[0] = 0;
    tat[0] = ct[0] - at[0];
    avgTAT = tat[0];
    avgWT = wt[0];

        for (int i = 1; i < processes; i++)
        {
            ct[i] = ct[i - 1] + bt[i];
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
            avgTAT += tat[i];
            avgWT += wt[i];
        }
        avgWT /= processes;

        printf("\n PID \t AT\t \tBT \tCT \tTAT \tWT");

        for (int i = 0; i < processes; i++)
        {
            printf("\n%d \t%d \t %d\t %d \t %d \t %d", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        }

        printf("\naverage turnaround time is %.3f\n", avgTAT);

        printf("\naverage wating timme is %.3f\n", avgWT);

        printf("\naverage waiting time is %.3f\n", avgWT);
}