class Solution {
public:
    int numSquares(int n) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
        int ans = 0;
        for (int i = 0; i * i <= n; ++i) {
            for (int j = i; j * j <= n; ++j) {
                for (int k = j; k * k <= n; ++k) {
                    for (int l = k; l * l <= n; ++l) {
                        if (i * i + j * j + k * k + l * l == n) {
                           vector<int>temp;
                           temp.emplace_back(i);
                           temp.emplace_back(j);
                           temp.emplace_back(k);
                           temp.emplace_back(l);
                           int zero=count(temp.begin(),temp.end(),0);
                           return temp.size()-zero;
                        }
                    }
                }
            }
        }
        return 2;
    }
};