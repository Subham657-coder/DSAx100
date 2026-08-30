class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int nonzero=0;
        for (int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nonzero++;
            }
        }
        return count(nums.begin(), nums.begin() + nonzero, 0);
    }
};