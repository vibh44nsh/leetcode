/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        printf("Memory allocation failed.\n");
        if (L) free(L);
        if (R) free(R);
        exit(1);
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    int n = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    temp = head;
    for (int i = 0; i < n; i++) {
        arr[i] = temp->val;
        temp = temp->next;
    }

    mergeSort(arr, 0, n - 1);

    temp = head;
    for (int i = 0; i < n; i++) {
        temp->val = arr[i];
        temp = temp->next;
    }

    free(arr); // Free the dynamically allocated array
    return head;
}