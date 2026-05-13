/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* dummy = (struct ListNode* ) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;
    for(int i = 0; i <= k; i++){
        fast = fast->next;
    }
    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode* temp = dummy;
    for(int i = 0; i < k; i++){
        temp = temp->next;
    }
    int x = temp->val;
    temp->val = slow->next->val;
    slow->next->val = x;

    return dummy->next;
}