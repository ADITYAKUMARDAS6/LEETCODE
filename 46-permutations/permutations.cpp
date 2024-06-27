class Solution {
public:
vector<vector<int>> res;
void helper(vector<int>&nums,int start){
    if(start==nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=start;i<nums.size();i++){
        swap(nums[start],nums[i]);
        helper(nums,start+1);
        swap(nums[start],nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
       int start=0;
        helper(nums,start);
        return res;
    }
};