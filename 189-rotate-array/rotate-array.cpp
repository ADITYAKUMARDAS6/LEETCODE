class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        k=k%n;
        vector<int> b;
        for(int i=n-k;i<n;i++)
            b.push_back(a[i]);
        for(int i=0;i<n-k;i++)
            b.push_back(a[i]);
        for(int i=0;i<n;i++)
            a[i]=b[i];
    }
};