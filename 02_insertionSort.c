#include <stdio.h>
int main()
{
    int n,i,j,key;
    int arr[100];
    printf("Enter the size of array : ");
    scanf("%d", &n);

    printf("Enter the elements in array :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }


    // Insertion Sort
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("\nSorted Array :");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
