/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return NULL;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        if (prev->next->val == prev->next->next->val) {
            int duplicate_val = prev->next->val;
            
            while (prev->next != NULL && prev->next->val == duplicate_val) {
                struct ListNode* temp = prev->next;
                prev->next = prev->next->next;
                free(temp);
            }
        } else {
            prev = prev->next;
        }
    }

    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}