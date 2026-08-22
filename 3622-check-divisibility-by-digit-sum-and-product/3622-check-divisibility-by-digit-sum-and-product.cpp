class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long prod=1;
        int og=n;
        while(n>0){
            sum+=n%10;
            prod*=n%10;
            n/=10;
        }
        if (og%(sum+prod)==0) return true;
        else return false;
    }
};