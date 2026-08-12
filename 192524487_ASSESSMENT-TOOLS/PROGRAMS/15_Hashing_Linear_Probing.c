#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void initTable() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == startIndex) {
            printf("Hash table is full. Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Key %d inserted at index %d\n", key, index);
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Index %d: empty\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;

    initTable();

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
