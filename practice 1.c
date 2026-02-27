
#include <stdio.h>

int main() {
    int arr[100], n, i, key;
    int low, high, mid;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);


    printf("\nLinear Search:\n");
    found = 0;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Element not found\n");
    }


    printf("\nBinary Search:\n");
    low = 0;
    high = n - 1;
    found = 0;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found == 0) {
        printf("Element not found\n");
    }

    return 0;
}
