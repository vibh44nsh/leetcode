/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return NULL;

    struct ListNode* curr = head;

    while (curr != NULL) {
        while (curr->next != NULL && curr->val == curr->next->val) {
            struct ListNode* del = curr->next;
            curr->next = del->next;
            del->next = NULL;
            free(del);
        }
        curr = curr->next;
    }

    return head;
}