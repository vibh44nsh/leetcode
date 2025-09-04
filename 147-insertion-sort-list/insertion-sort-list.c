/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* sortedHead = NULL;
    struct ListNode* current = head;

    while (current != NULL) {
        struct ListNode* nextNode = current->next;
        if (sortedHead == NULL || current->val < sortedHead->val) {
            current->next = sortedHead;
            sortedHead = current;
        } else {
            struct ListNode* search = sortedHead;
            while (search->next != NULL && search->next->val < current->val) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = nextNode;
    }

    return sortedHead;
}