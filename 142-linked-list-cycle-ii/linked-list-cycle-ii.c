/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) break;
    }
    if(!(fast && fast->next)) return NULL;
    struct ListNode* temp = head;
    while(temp != fast){
        temp = temp->next;
        fast = fast->next;
    }
    return temp;
}