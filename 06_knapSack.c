#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void printTable(float profit[], float weight[], float ratio[], int n)
{   int i;
    printf("Item\tProfit\tWeight\tRatio\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n", i + 1, profit[i], weight[i], ratio[i]);
    }
}

float knapsack(float profit[], float weight[], float ratio[], int n, int W, float x[])
{   int i,j;
    float temp,totalWeight,totalProfit;
    for ( i = 0; i < n - 1; i++)
    {
        for ( j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;
            }
        }
    }

    printf("\n The Sorted Table is :\n");
    printTable(profit, weight, ratio, n);

    totalWeight = 0;
    totalProfit = 0;

    for (i = 0; i < n; i++)
    {
        if (totalWeight + weight[i] <= W)
        {
            x[i] = 1;
            totalWeight += weight[i];
            totalProfit += profit[i];
        }
        else
        {
            x[i] = (W - totalWeight) / weight[i];
            totalWeight += weight[i] * x[i];
            totalProfit += profit[i] * x[i];
            break;
        }
    }
    return totalProfit;
}

void predefinedKnapsack(int n, float profit[], float weight[], int W)
{   
    float ratio[n], x[n],maxProfit;
    int i;

    for (i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    printf("\nThe Table is :\n");
    printTable(profit, weight, ratio, n);

    maxProfit = knapsack(profit, weight, ratio, n, W, x);
    printf("\nMaximum profit: %.2f\n", maxProfit);
}

int main()
{
    int n,w; // Number of items
    float profit[100];// Profits
    float weight[100]; // Weights
    clrscr();
   
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input profits
    printf("Enter the profits for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Profit for item %d: ", i + 1);
        scanf("%f", &profit[i]);
    }

    // Input weights
    printf("Enter the weights for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight for item %d: ", i + 1);
        scanf("%f", &weight[i]);
    }
     // Knapsack capacity
    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);


    predefinedKnapsack(n, profit, weight, W);
    getch();
    return 0;
}
