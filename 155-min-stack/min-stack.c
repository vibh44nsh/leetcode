#define MAX_STACK_SIZE 30000

typedef struct {
    int dataStack[MAX_STACK_SIZE]; 
    int minStack[MAX_STACK_SIZE]; 
    int dataTop;                   
    int minTop;
} MinStack;


MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    
    obj->dataTop = -1;
    obj->minTop = -1;
    
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->dataStack[++obj->dataTop] = val;
    
    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop]) {
        obj->minStack[++obj->minTop] = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->dataStack[obj->dataTop] == obj->minStack[obj->minTop]) {
        obj->minTop--;
    }
    
    obj->dataTop--;
}

int minStackTop(MinStack* obj) {
    return obj->dataStack[obj->dataTop];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/