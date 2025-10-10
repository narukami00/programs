#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define sp " "
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) x.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int findGCD(const std::vector<int>& arr) {
    int result = arr[0];
    for (const int& num : arr) {
        result = gcd(result, num);
        if (result == 1) {
            return 1; 
        }
    }
    return result;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int findLCM(const std::vector<int>& arr) {
    int result = arr[0];
    for (const int& num : arr) {
        result = lcm(result, num);
    }
    return result;
}

int rsum(int x, int y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}



int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }

        int ans=1,g=gcd(a[0][0],a[n-1][m-1]);
        vector<vector<bool>>dp(n,vector<bool>(m));

        vector<int>divs;
        for(int i=1;i*i<=g;i++){
            if(g%i==0){
                divs.push_back(i);
                if(i!=g/i)divs.push_back(g/i);
            }
        }

        for(int x:divs){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    dp[i][j]=0;
                }
            }
            dp[0][0]=1;
            
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(a[i][j]%x!=0)continue;

                    if(!dp[i][j] && i){
                        dp[i][j]=(dp[i-1][j]?1:0);
                    }

                    if(!dp[i][j] && j){
                        dp[i][j]=(dp[i][j-1]?1:0);
                    }
                }
            }

            if(dp[n-1][m-1]){
                ans=max(ans,x);
            }
        }

        cout<<ans<<endl;
    }
return 0;
}