class Solution {
public:
    int maxi(vector<int> &arr){
        int n=arr.size();
        int maxim=INT_MIN;
        for(int i=0;i<n;i++){
          maxim=max(maxim,arr[i]);
        }
        return maxim;
    }
    long long func(vector <int > &arr,int hours){
        long long totalhrs=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            totalhrs+=ceil((double) arr[i]/(double) hours);
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;int high=maxi(piles);
        int n=piles.size();
        int ans=INT_MAX;
        while (low<=high){
            int mid=(low+high)/2;
            long long total_hours=func(piles,mid);
            if(total_hours<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};