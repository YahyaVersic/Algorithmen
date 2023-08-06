#include <limits.h>

int minOperations(int* nums, int n){
    if(n == 1) return 0;
    if(n == 2) return (nums[1] <= nums[0] ? (nums[0]-nums[1])+1 : 0);

    int incCounter = 0;

    for(int i = 1; i < n; ++i) {
        if(nums[i] <= nums[i-1]){
            incCounter += nums[i-1] - nums[i] + 1;
            nums[i] = nums[i-1]+1;
        }
    }
    return incCounter;
}
