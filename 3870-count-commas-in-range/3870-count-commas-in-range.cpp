class Solution {
public:
    int countCommas(int n) {
        int sizen=to_string(n).length();
        int cnt=0;
        if (sizen<=3) return 0;
        else{
            for (int i=1000;i<=n;i++){
                cnt++;
            }
        }
        return cnt;
    }
};