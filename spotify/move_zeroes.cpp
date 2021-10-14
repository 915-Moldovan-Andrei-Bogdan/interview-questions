///tested on leetcode(20-23 ms)
///O(n)-time complexity O(1)-space complexity
///Andrei-Bogdan Moldovan


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int number_zeros=0;
        int iterator;
        int length=nums.size();
        for(iterator=0;iterator<length;iterator++){
            if(nums[iterator]==0)
                number_zeros+=1;
            else{
                nums[iterator-number_zeros]=nums[iterator];
            }
        }
        for(iterator=length-1-number_zeros+1;iterator<length;iterator++){
            nums[iterator]=0;
        }
    }
};
