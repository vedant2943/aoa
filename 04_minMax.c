#include <stdio.h>

// Implementing the min-max algorithm
void minMax(int arr[], int n)
{   
    // Declare the minimum and maximum elements
    int min, max,i;
    min = max = arr[0];

    // logic for updating min, max values
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
        else
        {
            continue;
        }
    }

    // Printing the minimum and maximum values of array
    printf("The minimum element in array is : %d", min);
    printf("\nThe maximum element in array is : %d", max);
}

int main()
{
    // Input the size of array
    int n,i;
    int arr[100];
    printf("Enter the size of array : ");
    scanf("%d", &n);

    // Input the elements in array
    printf("Enter the elements in array : ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // calling the minmax function
    minMax(arr, n);

    return 0;
}
