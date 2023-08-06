int searchInsert(int* nums, int numsSize, int target){
    int l = 0;
    int r = numsSize -1;

    int m;
    while(l <= r){
        m = (l+r) / 2;
        if (nums[m] < target){
            l = m+1;
        } else if (nums[m] > target){
            r = m-1;
        } else {
            return m;
        }
    }

    if(nums[m] < target){
        return m+1;
    } else{
        return m;
    }

}