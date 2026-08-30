class Solution {
public:
    int func(vector<int>&arr,int range){
        int subarr=1;int sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=range){
                sum+=arr[i];
            }
            else{
                subarr++;
                sum=arr[i];

            }
        }
        return subarr;

    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(high+low)/2;
            int subarrays=func(nums,mid);
            if(subarrays>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};