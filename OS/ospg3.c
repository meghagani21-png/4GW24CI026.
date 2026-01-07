#include<stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
  
    for (int i = 1; i < n ; i++ )
        wt[i] = bt[i-1] + wt[i-1];
}
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt);
    findTurnaroundTime(processes, n, bt, wt, tat);
    printf("\nProcess   Burst Time   Waiting"
           " Time   Turn-Around Time\n");
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d ", (i + 1));
        printf("       %d ", bt[i]);
        printf("       %d", wt[i]);
        printf("       %d\n", tat[i]);
    }
  
    printf("\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turn-around time = %.2f", (float)total_tat / (float)n);
}
 
void FCFS(int processes[], int n, int bt[]) {
    findAverageTime(processes, n, bt);
}
}
int main() {
    int n; 

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n]; 
    int bt[n]; 
    int priority[n];

    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Burst time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
 



      FCFS(processes, n, bt);
  
    
}


