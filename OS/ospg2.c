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
 
void RoundRobin(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];

    
    for (int i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
    }

    int time = 0;


    while (1) {
        int done = 1;

       
        for (int i = 0; i < n; i++) {
           
            if (bt[i] > 0) {
                done = 0;

                
                if (bt[i] <= quantum) {
                    time += bt[i];
                    wt[i] = time - bt[i];
                    bt[i] = 0;
                } else {
                    
                    time += quantum;
                    bt[i] -= quantum;
                }
            }
        }

        
        if (done == 1)
            break;
    }

  
    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    
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
 
  RoundRobin(processes, n, bt,3);


  
    
}


