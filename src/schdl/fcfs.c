#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void fcfs_schedule(Process p[], int n)
{
    int current_time = 0;
    int completed = 0;

    while (completed < n)
    {
        int idx = -1;
        int min_arrival = 999999;

        for (int i = 0; i < n; i++)
        {
            if (!p[i].completed)
            {
                if (p[i].arrival_time < min_arrival)
                {
                    min_arrival = p[i].arrival_time;
                    idx = i;
                }
                else if (p[i].arrival_time == min_arrival &&
                         p[i].id < p[idx].id)
                {
                    idx = i;
                }
            }
        }

        if (current_time < p[idx].arrival_time)
            current_time = p[idx].arrival_time;

        p[idx].waiting_time = current_time - p[idx].arrival_time;
        p[idx].turnaround_time = p[idx].waiting_time + p[idx].burst_time;

        current_time += p[idx].burst_time;

        p[idx].completed = 1;
        completed++;
    }
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    fcfs_schedule(p, n);

    print_results(p, n, "FCFS Scheduling");
    return 0;
}
#endif