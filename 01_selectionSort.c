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
The time complexity of Selection Sort is O(N2) as there are two nested loops:

One loop to select an element of Array one by one = O(N)
Another loop to compare that element with every other Array element = O(N)
Therefore overall complexity = O(N) * O(N) = O(N*N) = O(N2)

    
algorithm
 Selection-Sort (A)
fori← 1 to n-1 do
   min j ←i;
   min x ← A[i]
   for j ←i + 1 to n do
      if A[j] < min x then
         min j ← j
         min x ← A[j]
   A[min j] ← A [i]
   A[i] ← min x

