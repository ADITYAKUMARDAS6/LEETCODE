class Solution {
public:

    bool func(int mid, int k, vector<int>& v) {
        int n = v.size();
        int sum = 0;
        for (int i = 0; i < mid; i++) {
            sum += v[i];
        }
        if (sum >= k) return true;

        for (int i = mid; i < n; i++) {
            sum += v[i] - v[i - mid];
            if (sum >= k) return true;
        }
        return false;
    }

    int minSubArrayLen(int t, vector<int>& v) {
        int n=v.size();
        int s=0;
        int ans=s;
        int e=n;
        while(s<=e){
            int mid=(s+e)/2;
            if(func(mid,t,v)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};