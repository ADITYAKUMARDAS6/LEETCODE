
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans =0;
   
   for(int i=0;i<nums.size();i++){
       if((nums[i]+1)%3==0){
           ans++;
           continue;
       }
       else if((nums[i]-1)%3==0){
           ans++;
           continue;
       }
       
   }
        return ans;
    }
};
