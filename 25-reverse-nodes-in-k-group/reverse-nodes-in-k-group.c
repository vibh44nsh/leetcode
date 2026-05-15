/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseSublist(struct ListNode* head, struct ListNode* tail) {
    struct ListNode* prev = tail; 
    struct ListNode* curr = head;
    
    while (curr != tail) {
        struct ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode* groupPrev = dummy;
    struct ListNode* curr = head;

    while (curr) {
        struct ListNode* kth = curr;
        int count = 0;
        while (count < k && kth != NULL) {
            kth = kth->next;
            count++;
        }
        
        if (count < k) break;

        struct ListNode* groupNext = kth;

        struct ListNode* newGroupHead = reverseSublist(curr, groupNext);
        
        groupPrev->next = newGroupHead;
        
        groupPrev = curr; 
        curr = groupNext; 
    }

    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}