class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int sz = arr.size();
        vector<int> sumState(sz);
        for(int currIndx = 0; currIndx < arr.size(); currIndx++){
            int maxTillNow = arr[currIndx];
            for(int prevIndx = currIndx; prevIndx > max(-1, currIndx - k); prevIndx--){
                maxTillNow = max(maxTillNow, arr[prevIndx]);
                int segLen = currIndx - prevIndx + 1;
                int prevSegContri = ((prevIndx - 1 > -1) ? sumState[prevIndx-1] : 0);
                int currentSegContri = (maxTillNow * segLen);
                sumState[currIndx] = max(prevSegContri + currentSegContri, sumState[currIndx]);
            }
        }
        return sumState[sz-1];
    }
};