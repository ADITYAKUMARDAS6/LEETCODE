
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        DPSolver;
        // Method 1 - make seperate array containing +ve and -ve integers
        vector<int> pos , neg;

        for(auto x : nums){
            if(x >= 0){
                pos.push_back(x);
            }
            else{
                neg.push_back(x);
            }
        }

        vector<int> ans;

        for(int i = 0 ; i < pos.size(); i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;


        // Method 2 - let i and j point to +ve and - ve element
        // vector<int> ans;
        // int n = nums.size(), i = 0 , j = 0;

        // while(i < n && j < n){
        //     // let i point to +ve element
        //     while(i < n && nums[i] < 0){
        //         i++;
        //     }

        //     // let j point to +ve element
        //     while(j < n && nums[j] > 0){
        //         j++;
        //     }

        //     // now store +ve and -ve element
        //     ans.push_back(nums[i]);
        //     ans.push_back(nums[j]);

        //     i++,j++;
        // }
        // return ans;
    }
};