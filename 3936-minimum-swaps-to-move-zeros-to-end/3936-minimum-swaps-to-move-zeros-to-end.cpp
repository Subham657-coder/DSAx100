class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int nonzero=0;
        for (int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nonzero++;
            }
        }
        int swaps=0;
        for (int i = 0; i < nonzero; i++){
            if(nums[i]==0) swaps++;
        }
        return swaps;
    }
};