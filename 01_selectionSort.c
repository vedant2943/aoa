#include <stdio.h>
int main()
{
    // Input no of elements
    int n,j,i,mindex, marray;
    int arr[100];
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter the elements in array : ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Selection Sort Logic
    for (i = 0; i < n-1; i++)
    {
        mindex = i;
        marray = arr[i];


        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < marray)
            {
                mindex = j;
               marray = arr[j];
            }
        }
            arr[mindex] = arr[i];
            arr[i] = marray;
    }

    // Sorted array output
    printf("The sorted array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}


