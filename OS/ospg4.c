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
 
void SJF(int processes[], int n, int bt[]) {
  
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (bt[j] > bt[j+1]) {
              
                int temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
    
    findAverageTime(processes, n, bt);
}
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
 
 SJF(processes, n, bt);


  
    
}


