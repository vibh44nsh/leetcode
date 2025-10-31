int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top > -1 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--]; 
            result[prevIndex] = i - prevIndex;
        }
        stack[++top] = i;
    }
    free(stack);
    return result;
}