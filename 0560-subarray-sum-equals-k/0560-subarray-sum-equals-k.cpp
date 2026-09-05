class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sm=0;
        map <int,int> mpp;
        mpp[sm]++;
        int cnt=0;
        for (int i=0; i<nums.size();i++){
            sm+=nums[i];
            int x=sm-k;
            cnt+=mpp[x];
            mpp[sm]++;
        }
        return cnt;
    }
    
};