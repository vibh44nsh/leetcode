typedef struct {
    int* q1;
    int* q2;
    int q1_size;
    int q2_size;
    int q1_capacity;
    int q2_capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1_capacity = 1000;
    stack->q2_capacity = 1000;
    stack->q1 = (int*)malloc(stack->q1_capacity * sizeof(int));
    stack->q2 = (int*)malloc(stack->q2_capacity * sizeof(int));
    stack->q1_size = 0;
    stack->q2_size = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->q1[obj->q1_size++] = x;
}

int myStackPop(MyStack* obj) {
    if (obj->q1_size == 0) return -1;
    
    while (obj->q1_size > 1) {
        obj->q2[obj->q2_size++] = obj->q1[0];
        for (int i = 0; i < obj->q1_size - 1; i++) {
            obj->q1[i] = obj->q1[i + 1];
        }
        obj->q1_size--;
    }
    
    int poppedElement = obj->q1[0];
    obj->q1_size--;
    
    int* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    
    int temp_size = obj->q1_size;
    obj->q1_size = obj->q2_size;
    obj->q2_size = temp_size;
    
    return poppedElement;
}

int myStackTop(MyStack* obj) {
    return obj->q1[obj->q1_size - 1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->q1_size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}