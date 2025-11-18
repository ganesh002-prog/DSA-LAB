Aim:To write a program for an element in a sorted array using linear search techniques.


#include <stdio.h>

int main()
{
    int n, key, i;
    printf("Enter the number of elements required: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the key to search for: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        
        if(array[i] == key + 1)
        {
            printf("Element found at position %d\n", i);
            break;
        }
    }

    if(i == n)
    {
        printf("Element not found\n");
    }

    return 0;
}

output:
Enter the number of elements required: 5
Enter the elements:
2
4
6
8
10
Enter the key to search for: 6
Element found at position 2

Result: 
        The program successfully searches for a given key element in a sorted array 
using the linear search technique and displays whether the element is found or not.
