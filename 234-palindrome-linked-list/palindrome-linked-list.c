/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if(head==NULL) return true;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode *current = slow;
    struct ListNode *prev = NULL;
    struct ListNode *temp = NULL;
    while(current!=NULL){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    current = head;
    while(prev!=NULL){
        if(prev->val != current->val) return false;
        current = current->next;
        prev = prev->next;
    }
    return true;
}