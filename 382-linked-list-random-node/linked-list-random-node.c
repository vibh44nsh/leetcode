/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



typedef struct {
    struct ListNode* head;
} Solution;

Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->head = head;
    srand(time(NULL)); 
    return obj;
}

int solutionGetRandom(Solution* obj) {
    int n = 0;
    struct ListNode* curr = obj->head;
    
    while (curr) {
        n++;
        curr = curr->next;
    }
    
    int r = rand() % n;

    curr = obj->head;
    for (int i = 0; i < r; i++) {
        curr = curr->next;
    }
    
    return curr->val;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/