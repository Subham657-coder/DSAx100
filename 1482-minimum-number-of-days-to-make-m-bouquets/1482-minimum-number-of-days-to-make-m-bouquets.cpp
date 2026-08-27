class Solution {
public:
    long long minel(vector<int> &arr){
        long long mini=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if (arr[i]<mini){
                mini=arr[i];
            }
        }
        return mini;
    }
    long long maxel(vector<int> &arr){
        long long maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if (arr[i]>maxi){
                maxi=arr[i];
            }
        }
        return maxi;
    }
    bool possible(vector<int> &arr,int day,int m,int n){
        int cnt=0;int bouq=0;
        for(int i=0;i<arr.size();i++){
            if (arr[i]<=day){
                cnt+=1;
            }
            else{
                bouq+=(cnt/n);
                cnt=0;
            }
        }
        bouq+=(cnt/n);
        if (bouq>=m){
            return true;
        }
        else{
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val= m * 1LL * k * 1LL;
        if (val>bloomDay.size()) return -1;
        long long low=minel(bloomDay);
        long long high=maxel(bloomDay);
        while(low<=high){
            long long mid=(low+high)/2;
            bool possiblity=possible(bloomDay,mid,m,k);
            if (possiblity==true){
                high=mid-1; 
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};