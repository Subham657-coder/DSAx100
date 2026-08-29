class Solution {
public:
    bool canWePlace(vector<int>& arr,int dist,int balls){
        int cntballs=1;
        int lastball=arr[0];
        for (int i=0;i<arr.size();i++){
            if (arr[i]-lastball>=dist){
                cntballs++;
                lastball=arr[i];
            }
        }
        if (cntballs>=balls) return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=1;
        int high=position[n-1]-position[0];
        while(low<=high){
            int mid=(low+high)/2;
            if (canWePlace(position,mid,m)==true){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};