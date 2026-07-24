#include <stdio.h>

#define MAX 100

int maxHeap[MAX];
int minHeap[MAX];
int maxSize = 0, minSize = 0;

// ---------- Max Heap ----------
void maxInsert(int value) {
    int i = maxSize++;
    while (i > 0 && value > maxHeap[(i - 1) / 2]) {
        maxHeap[i] = maxHeap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    maxHeap[i] = value;
}

int maxDelete() {
    if (maxSize == 0) {
        printf("Max Heap is empty!\n");
        return -1;
    }

    int root = maxHeap[0];
    int last = maxHeap[--maxSize];

    int i = 0;
    while (2 * i + 1 < maxSize) {
        int child = 2 * i + 1;

        if (child + 1 < maxSize && maxHeap[child + 1] > maxHeap[child])
            child++;

        if (last >= maxHeap[child])
            break;

        maxHeap[i] = maxHeap[child];
        i = child;
    }

    maxHeap[i] = last;
    return root;
}

void printMaxHeap() {
    printf("Max Heap: ");
    for (int i = 0; i < maxSize; i++)
        printf("%d ", maxHeap[i]);
    printf("\n");
}

// ---------- Min Heap ----------
void minInsert(int value) {
    int i = minSize++;
    while (i > 0 && value < minHeap[(i - 1) / 2]) {
        minHeap[i] = minHeap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap[i] = value;
}

int minDelete() {
    if (minSize == 0) {
        printf("Min Heap is empty!\n");
        return -1;
    }

    int root = minHeap[0];
    int last = minHeap[--minSize];

    int i = 0;
    while (2 * i + 1 < minSize) {
        int child = 2 * i + 1;

        if (child + 1 < minSize && minHeap[child + 1] < minHeap[child])
            child++;

        if (last <= minHeap[child])
            break;

        minHeap[i] = minHeap[child];
        i = child;
    }

    minHeap[i] = last;
    return root;
}

void printMinHeap() {
    printf("Min Heap: ");
    for (int i = 0; i < minSize; i++)
        printf("%d ", minHeap[i]);
    printf("\n");
}

// ---------- Main ----------
int main() {

    int arr[] = {40, 20, 35, 10, 15, 30, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        maxInsert(arr[i]);
        minInsert(arr[i]);
    }

    printMaxHeap();
    printMinHeap();

    printf("\nDeleted from Max Heap: %d\n", maxDelete());
    printMaxHeap();

    printf("\nDeleted from Min Heap: %d\n", minDelete());
    printMinHeap();

    return 0;
}
