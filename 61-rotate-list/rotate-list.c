/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0) return head;
    int length = 1;
    struct ListNode* tail = head;
    while(tail->next){
        tail = tail->next;
        length++;
    }
    k %= length;
    if(k == 0){
        return head;
    }
    tail->next = head;
    struct ListNode* tail_new = head;
    for(int i = 0; i < length - k - 1; i++){
        tail_new = tail_new->next;
    }
    struct ListNode* head_new = tail_new->next;
    tail_new->next = NULL;
    return head_new;
}