#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        int freq[100001]={0};
        int xMax=0, xMin=INT_MAX;
        for(int x: nums){
            freq[x]++;
            xMax=max(x, xMax);
            xMin=min(x, xMin);
        }
        vector<vector<int>> ans(n/3);
        vector<int> vec3(3);
        int count=0, i=0;
        for(int x=xMin; x<=xMax; x++){
            for(;freq[x]>0; freq[x]--, count=(count+1)%3){
                vec3[count]=x;
                if (count==2){
                    if (x-vec3[0]>k) return {};
                    ans[i++]=vec3;
                }
            }
        }
        return move(ans);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();