/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    if(!head->next) return NULL;
    
    struct ListNode* ptr= head->next;
    int sum=0;
    while(ptr->val!=0){
        sum += ptr->val;
        ptr = ptr->next;
    }
    

    head->next->val= sum;
    
    head->next->next= mergeNodes(ptr);
    
    return head->next;
}