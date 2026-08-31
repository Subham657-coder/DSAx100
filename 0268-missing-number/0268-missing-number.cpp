class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long sum=1LL*n*(n+1)/2;
        long long s2=0;
        for (int i=0;i<n;i++){
            s2+=nums[i];
        }
        return (sum-s2);
    }
};