#include<stdio.h>

void main()
{
    int processes;
    printf("Enter the no of processes: ");
    scanf("%d", &processes);

    int time=0, pid[processes], at[processes], bt[processes], ct[processes], tat[processes], wt[processes], isExecuted[processes];
    float avgWT=0, avgTAT=0;
    
    for (int i = 0; i < processes; i++)
    {
        printf("Enter processs id: ");
        scanf("%d", &pid[i]);
        printf("Enter arrival time of processs %d: ", i);
        scanf("%d", &at[i]);
        printf("Enter burst time of processs %d: ", i);
        scanf("%d", &bt[i]);
        isExecuted[i]=0;
    }

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < processes-1; j++)
        {
            if (at[j] > at[j + 1])
            {
                int temp = pid[j];
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

    while(1) {
        int shortest = -1;
        int min_bt = 999999;
        int completed = 0;

        for(int i = 0; i < processes; i++) {
            if(isExecuted[i] == 0 && at[i] <= time) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    shortest = i;
                }
            }
            if(isExecuted[i] == 1) {
                completed++;
            }
        }

        if(completed == processes) {
            break;
        }

        if(shortest == -1) {
            time++;
        } else {
            ct[shortest] = time + bt[shortest];
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            avgTAT += tat[shortest];
            avgWT += wt[shortest];
            isExecuted[shortest] = 1;
            time = ct[shortest];
        }
    }

    avgTAT /= processes;
    avgWT /= processes;

    printf("\n PID \t AT\t \tBT \tCT \tTAT \tWT");
    for (int i = 0; i < processes; i++)
    {
        printf("\n%d \t%d \t %d\t %d \t %d \t %d", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\naverage turnaround time is %.3f\n", avgTAT);
    printf("\naverage wating timme is %.3f\n", avgWT);
}
