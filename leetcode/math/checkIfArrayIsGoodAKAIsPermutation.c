bool isGood(int* nums, int numsSize){
    int occ = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == numsSize -1){
            occ++;
        }
    }
    if (occ != 2){
        return false;
    }

    bool b;
    for(int i = 1; i < numsSize; i++){
        b = false;
        for(int j = 0; j < numsSize; j++){
            if(i == nums[j]){
                b = true;
                break;
            }
        }
        if (b == false){
            return false;
        }
    }

    return true;
}
