Aim: To implement a program in C that locates a specific element in a sorted array efficiently using binary search.


#include<stdio.h>
int main()
{
    int i,n,key;
    printf("enter the number of elements n: \n");
    scanf("%d", &n);
    
    int array[n];
    printf("enter the elements: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("enter the key \n");
    scanf("%d",&key);
    int mid,start=0,end=n-1;
    
    while(start<=end)
    {
        mid = (start+end)/2;
        printf("\nmid-%d, Key-%d", mid, key);
        if(array[mid]==key)
        {
            printf("found at position %d", mid+1);
            break;
        }
        if(array[mid]<key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if(start>end)
    {
        printf("not found");
    }
}



OUTPUT:
Enter the number of elements: 5
Enter 5 sorted elements:
1 3 5 7 9
Enter the key to search: 7

mid = 2, key = 7
mid = 3, key = 7
Found at position 4

RESULT:
Program sucessfully demonstrates linear search.
