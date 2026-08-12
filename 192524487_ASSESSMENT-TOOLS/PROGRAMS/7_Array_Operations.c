#include <stdio.h>

void display(int arr[], int n) {
    int i;
    printf("Array elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int arr[], int *n, int pos, int value) {
    int i;
    if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }
    for (i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*n)++;
}

void deleteElement(int arr[], int *n, int pos) {
    int i;
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }
    for (i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

int main() {
    int arr[100], n, choice, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position and value to insert: ");
                scanf("%d %d", &pos, &value);
                insert(arr, &n, pos, value);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            case 3:
                display(arr, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
