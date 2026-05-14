/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA || !headB) return NULL;

    struct ListNode* currA = headA;
    struct ListNode* currB = headB;

    while(currA != currB){
        currA = (currA == NULL) ? headB : currA->next;
        currB = (currB == NULL) ?  headA : currB->next;
    }
    return currA; // or currB both will have either NULL if no intersection or will have the same intersecting value
}