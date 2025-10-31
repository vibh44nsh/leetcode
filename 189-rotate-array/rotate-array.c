void rotate(int* nums, int n, int k) {
    k = k % n;
    for(int i = 0; i < n/2; i++) {
        int tmp = nums[i];
        nums[i] = nums[n-1-i];
        nums[n-1-i] = tmp;
    }
    for(int i = 0; i < k/2; i++) {
        int tmp = nums[i];
        nums[i] = nums[k-1-i];
        nums[k-1-i] = tmp;
    }
    for(int i = 0; i < (n-k)/2; i++) {
        int tmp = nums[k+i];
        nums[k+i] = nums[n-1-i];
        nums[n-1-i] = tmp;
    }
}