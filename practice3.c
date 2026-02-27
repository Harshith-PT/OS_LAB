
#include <stdio.h>

int main() {
    int n, i, j, found = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                found = 1;
                break;
            }
        }
        if(found == 1)
            break;
    }

    if(found == 1)
        printf("Duplicates found in the array.\n");
    else
        printf("No duplicates in the array.\n");

    return 0;
}
