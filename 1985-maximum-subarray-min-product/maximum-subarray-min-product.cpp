class Solution
{
public:
    int maxSumMinProduct(vector<int> &n)
    {
        // Initialize a variable 'res' to store the maximum sum of the subarray
        long res = 0;
        // Create a vector 'dp' to store the prefix sums of the input vector 'n'
        vector<long> dp(n.size() + 1);
        // Create a vector 'st' to store the indices of the integers in 'n' that are used to calculate the maximum sum
        vector<long> st;
        // Calculate the prefix sums of the input vector 'n' and store them in the 'dp' vector
        for (int i = 0; i < n.size(); ++i)
        {
            dp[i + 1] = dp[i] + n[i];
        }
        // Iterate through the input vector 'n'
        for (int i = 0; i <= n.size(); ++i)
        {
            // While the 'st' vector is not empty and the current integer in 'n' is greater than or equal to the last integer in 'st'
            while (!st.empty() && (i == n.size() || n[st.back()] > n[i]))
            {
                // Pop the last integer in 'st' and store it in the variable 'j'
                int j = st.back();
                st.pop_back();
                // Update the maximum sum of the subarray by calculating the sum of the subarray between the last element in 'st' and the current element 'i'
                // and multiplying it by the value of the popped integer 'j'
                res = max(res, n[j] * (dp[i] - dp[st.empty() ? 0 : st.back() + 1]));
            }
            // Push the current index 'i' into the 'st' vector
            st.push_back(i);
        }
        // Return the maximum sum of the subarray mod 1000000007 to prevent overflow
        return res % 1000000007;
    }
};