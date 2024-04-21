#include <stdio.h>
#include<conio.h>

int jobSequencing(int deadline[], int profit[], int n, int sequence[]) {
    int i,j,temp1,temp2,finalResult;
    int result[100];
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                 temp1 = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp1;

                 temp2 = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp2;
            }
        }
    }

    
    for (i = 0; i < n; i++) {
        result[i] = -1;
    }

    for ( i = 0; i < n; i++) {
        for ( j = (deadline[i] - 1); j >= 0; j--) {
            if (result[j] == -1) {
                result[j] = i;
                break;
            }
        }
    }

    finalResult = 0;
    for ( i = 0; i < n; i++) {
        if (result[i] != -1) {
            finalResult += profit[result[i]];
            sequence[i] = result[i] + 1; // Storing job sequence
        }
    }
    return finalResult;
}

int main() {
    int n; // Number of jobs
    int deadline[100] ; // Deadlines
    int profit[100]; // Profits
    int sequence[100]; // Array to store job sequence

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Deadlines
    printf("Enter the deadlines for each job:\n");
    for ( i = 0; i < n; i++) {
        printf("Deadline for job %d: ", i + 1);
        scanf("%d", &deadline[i]);
    }

    // Profits
    printf("Enter the profits for each job:\n");
    for ( i = 0; i < n; i++) {
        printf("Profit for job %d: ", i + 1);
        scanf("%d", &profit[i]);
    }


    int totalProfit = jobSequencing(deadline, profit, n, sequence);

     printf("The total profit is %d\n", totalProfit);
    printf("Job sequence: ");
    for ( i = 0; i < n; i++) {
        if (sequence[i] != 0) {
            printf("%d ", sequence[i]);
        }
    }
    printf("\n");
    getch();
    return 0;
}
