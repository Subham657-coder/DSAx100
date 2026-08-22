class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        int n=nums.size();
        int first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int last=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(first==n || nums[first]!=target){
            ans.insert(ans.end(),{-1,-1});
        }
        else{
            ans.insert(ans.end(),{first,last-1});
        }
        return ans;
    }
};
