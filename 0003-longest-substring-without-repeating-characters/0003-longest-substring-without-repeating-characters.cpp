#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        int start=0;
        vector <int> last(256,-1);
        for (int i=0;i<n;i++){
            if (last[s[i]]>=start){
                start=last[s[i]]+1;
            }
            last[s[i]]=i;
            maxi=max(maxi,i-start+1);
        }
        return maxi;



        return maxi;
    }
};