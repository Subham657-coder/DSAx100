class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, long long> mp;

        long long prefix = 0;
        long long ans = LLONG_MIN;

        for (int x : nums) {

            // Check if x can be the ending element
            if (mp.find(x - k) != mp.end()) {
                ans = max(ans, prefix + x - mp[x - k]);
            }

            if (mp.find(x + k) != mp.end()) {
                ans = max(ans, prefix + x - mp[x + k]);
            }

            // Store minimum prefix before x
            if (mp.find(x) == mp.end()) {
                mp[x] = prefix;
            } else {
                mp[x] = min(mp[x], prefix);
            }

            prefix += x;
        }

        return ans == LLONG_MIN ? 0 : ans;
    }
};