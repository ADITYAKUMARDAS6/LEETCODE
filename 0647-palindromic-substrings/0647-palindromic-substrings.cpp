class Solution {
public:
    vector<long long> powers;
    int p = 31, mod = 1e9+7;
    vector<long long> makeHash(string s){
        long long n = s.size();
        powers.resize(n+1,1);
        for(int i=1;i<=n;i++){
            powers[i] = (powers[i-1]%mod * p%mod)%mod;
        }
        vector<long long> hash(n+1,0);
        for(int i=1;i<=n;i++){
            hash[i] = (hash[i-1]%mod + (((s[i-1]-'a')%mod)*powers[i]%mod)%mod)%mod;
        }
        return hash;
    }
    int countSubstrings(string s) {
        string t = s;
        int n = s.size();
        reverse(t.begin(),t.end());
        vector<long long> fh = makeHash(s); //Forward Hash
        vector<long long> bh = makeHash(t); //Backward Hash
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                long long v1 = ((fh[j] - fh[i-1] + mod)%mod * powers[n-j+1]%mod)%mod;
                long long v2 = ((bh[n-i+1] - bh[n-j] + mod)%mod * powers[i]%mod)%mod;
                if(v1 == v2)    ans++;
            }
        }
        return ans;
    }
};