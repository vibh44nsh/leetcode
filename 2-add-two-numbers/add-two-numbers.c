/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode* ) malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* curr = dummy;
    int carry = 0;
    int sum;
    while(l1 || l2 || carry != 0){
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        sum = x + y + carry;
        carry = sum/10;
        curr->next = (struct ListNode* ) malloc(sizeof(struct ListNode));
        curr->next->val = sum%10;
        curr->next->next = NULL;
        curr = curr->next;
        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
    }
    return dummy->next;
}