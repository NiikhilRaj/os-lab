#include <stdio.h>
#include <limits.h> 

struct Process {
    int pid, at, burst, rt, ct, wt, tat;
};

void findSRTF(struct Process p[], int n) {
    int completed = 0, time = 0, minIndex;
    int minrt = INT_MAX;

    while (completed < n) {
        minIndex = -1;
        minrt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].rt < minrt) {
                minrt = p[i].rt;
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            time++;
            continue;
        }

        p[minIndex].rt--;
        time++;

        if (p[minIndex].rt == 0) {
            completed++;
            p[minIndex].ct = time;
            p[minIndex].tat = p[minIndex].ct - p[minIndex].at;
            p[minIndex].wt = p[minIndex].tat - p[minIndex].burst;
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter at time and burst time for process %d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].burst);
        p[i].pid = i + 1;
        p[i].rt = p[i].burst;
    }

    findSRTF(p, n);

    printf("\nPID\tat\tBurst\tct\ttat\twt\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].burst, 
               p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
