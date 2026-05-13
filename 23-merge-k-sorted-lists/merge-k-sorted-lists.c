/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    struct ListNode* dummy = (struct ListNode* ) malloc(sizeof(struct ListNode));
    struct ListNode* temp = dummy;
    dummy->next = NULL;

    while (1) {
        int minIndex = -1;
        int minVal = 1e9;

        for (int i = 0; i < listsSize; i++) {
            if (lists[i] != NULL && lists[i]->val < minVal) {
                minVal = lists[i]->val;
                minIndex = i;
            }
        }
        if (minIndex == -1) break;

        temp->next = lists[minIndex];
        temp = temp->next;

        lists[minIndex] = lists[minIndex]->next;
    }

    return dummy->next;
}
