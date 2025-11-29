Aim:
To develop a program that performs a linear search on a sorted list of integers and determines whether a specified element is present in the list.

    #include <stdio.h>

int main()
{
    int n, key, i;

    printf("Enter how many elements the array should contain: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted integers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value you want to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("The element %d is found at index %d.\n", key, i);
            break;
        }
    }

    if(i == n)
    {
        printf("The element %d is not present in the array.\n", key);
    }

    return 0;
}

output:
Enter how many elements the array should contain: 5
Enter 5 sorted integers:
2
4
6
8
10
Enter the value you want to search: 6
The element 6 is found at index 2.
result:
The program successfully implements linear search on a sorted array.
 It checks each element sequentially and reports whether the desired value is found and at which postion
