#include <limits.h>

int minOperations(int* nums, int n){
    if(n == 1) return 0;
    if(n == 2) return (nums[1] <= nums[0] ? (nums[0]-nums[1])+1 : 0);

    int incCounter = 0;

    for(int i = 0; i < n; ++i) {
        int cur = i;
        for(int j=i+1; j < n; j++){
            if(nums[j] <= nums[i]){
                incCounter += (nums[i] - nums[j]) + 1;
                nums[j] = nums[i] + 1;
            }
        }

    }
    return incCounter;
}
