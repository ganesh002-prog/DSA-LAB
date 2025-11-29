AIM:
To write a C program that searches for a given number in a sorted list using the binary search technique and displays whether the number is present or not.

Program:
#include <stdio.h>

int main() {
    int n, key, low, high, mid;

    printf("Enter how many numbers you want: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the %d numbers in sorted order:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number you want to find: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;
    int found = 0;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("The number %d is found at index %d\n", key, mid);
            found = 1;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(found == 0) {
        printf("The number is not present in the list.\n");
    }

    return 0;
}

OUTPUT:
Enter how many numbers you want: 5
Enter the 5 numbers in sorted order:
2 4 6 8 10
Enter the number you want to find: 8
The number 8 is found at index 3

RESULT
The program successfully uses binary search to check whether a given number exists in a sorted array.
