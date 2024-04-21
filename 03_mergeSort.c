#include <stdio.h>

void combine(int arr[], int low, int mid, int high)
{
    int merge[100],idx1,idx2,x,i,j;
    // new array
    merge[high - low + 1];

    // Maintaining the indexes
    idx1 = low;
    idx2 = mid + 1;
    x = 0;

    // comparing both the arrays
    while ((idx1 <= mid) && (idx2 <= high))
    {
        if (arr[idx1] < arr[idx2])
        {
            merge[x] = arr[idx1];
            x++;
            idx1++;
        }
        else
        {
            merge[x] = arr[idx2];
            x++;
            idx2++;
        }
    }

    // if first list is incomplete
    while (idx1 <= mid)
    {
        merge[x] = arr[idx1];
        x++;
        idx1++;
    }

    // if second list is incomplete
    while (idx2 <= high)
    {
        merge[x] = arr[idx2];
        x++;
        idx2++;
    }

    // Copying the elements to the main array
    for (i = low, j = 0; i <= high; i++, j++)
    {
        arr[i] = merge[j];
    }
}

void mergeSort(int arr[], int low, int high)
{      
    int mid;
    if (low < high) // Base Condition
    {
        mid = (low + high) / 2;

        // dividing into 2 sublists
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // combine function
        combine(arr, low, mid, high);
    }
}

int main()
{
    int n,i;
    int arr[100];
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter the elements in array : ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("The sorted array is : ");
    for ( i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }


    return 0;
}
