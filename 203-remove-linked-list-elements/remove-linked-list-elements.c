/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp); // Free the old head
    }
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    
    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;
            struct ListNode* temp = curr;
            curr = curr->next;
            free(temp);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    return head;
}