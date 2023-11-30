#include <stdio.h>
#include <stdlib.h>

void main()
{
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;
    system("clear");
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    // Calculate the waiting time and turnaround time for the first process
    wt[0] = wtavg = 0; // Initialize the waiting time for the first process to 0
    tat[0] = tatavg = bt[0]; // Set the turnaround time for the first process equal to its burst time

    // Loop through each process starting from the second process (i = 1)
    for (i = 1; i < n; i++)
    {
        // Calculate the waiting time for the current process by adding the burst time of the previous process to its waiting time
        wt[i] = wt[i - 1] + bt[i - 1];

        // Calculate the turnaround time for the current process by adding the burst time of the current process to the turnaround time of the previous process
        tat[i] = tat[i - 1] + bt[i];

        // Calculate the average waiting time by summing up the waiting times of all processes
        wtavg = wtavg + wt[i];

        // Calculate the average turnaround time by summing up the turnaround times of all processes
        tatavg = tatavg + tat[i];
    }

    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time -- %f", wtavg / n);
    printf("\nAverage Turnaround Time -- %f", tatavg / n);
}