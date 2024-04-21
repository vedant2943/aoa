#include <stdio.h>

// Function to implement binary search
int binarySearch(int arr[], int low, int high, int target)
{   int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;      // non-recursive approach

            // return binarySearch(arr, mid+1, high, target);
        }
        else
        {
            high = mid - 1;      // non-recursive approach

            // return binarySearch(arr, low, mid-1, target);
        }
    }
    return -1;
}

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n)
{   int i,j,temp;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // Changed to sort in ascending order
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("The sorted array is : ");
    for ( i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    // Input the size of array
    int n,i,target,targetIndex;
    int arr[100];
    printf("Enter the size of array : ");
    scanf("%d", &n);

    // Input the elements in array
    printf("Enter the elements in array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input the target element
    printf("Enter the target element : ");
    scanf("%d", &target);

    bubbleSort(arr, n);
    targetIndex = binarySearch(arr, 0, n - 1, target);

    // Checking the final condition of returned index
    if (targetIndex == -1)
    {
        printf("Target element not found in the array");
    }
    else
    {
        printf("\nTarget element is found at index %d after array is sorted", (targetIndex));
    }
    return 0;
}

