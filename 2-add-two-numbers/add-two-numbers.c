/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node_t;

node_t* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    node_t* dummyHead = malloc(sizeof(node_t));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    node_t* curr = dummyHead;
    int carry = 0;
    int sum;
    while(l1 != NULL || l2 != NULL || carry != 0){
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        sum = carry + x + y;
        carry = sum/10;
        curr->next = malloc(sizeof(node_t));
        curr->next->val = sum % 10;
        curr->next->next = NULL;
        curr = curr->next;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    node_t *out = dummyHead->next;
    return out;
}