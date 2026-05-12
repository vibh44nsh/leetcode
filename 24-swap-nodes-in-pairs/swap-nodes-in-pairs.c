/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummy = (struct ListNode* ) malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *prev, *curr;
    prev = dummy;
    curr = head;
    while(curr && curr->next){
        struct ListNode* nextPair = curr->next->next;
        struct ListNode* second = curr->next;

        second->next = curr;
        curr->next = nextPair;
        prev->next = second;

        prev = curr;
        curr = nextPair; 
    }
    return dummy->next;
}