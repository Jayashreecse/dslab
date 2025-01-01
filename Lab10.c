#include <stdio.h>
#include <stdlib.h>

int key[20], n, m;
int *ht;
int count = 0;

void insert(int key) {
    int index = key % m;
    while (ht[index] != -1) {
        index = (index + 1) % m;
    }
    ht[index] = key;
    count++;
}

void display() {
    int i;
    if (count == 0) {
        printf("\nHash Table is empty");
        return;
    }
    printf("\nHash Table contents are:\n");
    for (i = 0; i < m; i++) {
        printf("\n T[%d] --> %d", i, ht[i]);
    }
}

int main() {
    int i;
    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);
    printf("\nEnter the memory size (m) for the hash table: ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));
    if (!ht) {
        printf("\nMemory allocation failed.");
        return 1;
    }

    for (i = 0; i < m; i++) {
        ht[i] = -1;
    }

    printf("\nEnter the four-digit key values (K) for %d Employee Records:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key[i]);
    }

    for (i = 0; i < n; i++) {
        if (count == m) {
            printf("\nHash table is full. Cannot insert the record for key %d", key[i]);
            break;
        }
        insert(key[i]);
    }

    display();
    return 0;
}
