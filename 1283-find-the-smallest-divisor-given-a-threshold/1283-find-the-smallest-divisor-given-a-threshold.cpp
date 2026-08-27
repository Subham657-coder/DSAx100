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
    long long func(vector <int > &arr,int divisor){
        long long t=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            t+=ceil((double) arr[i]/(double) divisor);
        }
        return t;
    }      
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;int high=maxi(nums);
        int n=nums.size();
        int ans=INT_MAX;
        while (low<=high){
            int mid=(low+high)/2;
            long long div=func(nums,mid);
            if(div<=threshold){
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