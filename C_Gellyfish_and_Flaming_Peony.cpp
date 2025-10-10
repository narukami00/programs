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

const int INF=LLONG_MAX;

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        cin>>arr;
        int glob=findGCD(arr);

        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==glob)cnt++;
        }

        if(cnt>0){
            cout<<n-cnt<<endl;
            continue;
        }

        set<int>st;for(auto it:arr)st.insert(it);
        vector<int>brr;for(auto it:st)brr.pb(it);

        int mx=brr.back();
        vector<int>cost(mx+1,INF);
        queue<int>q;

        for(auto it:brr){cost[it]=0;q.push(it);}

        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(u==glob)break;

            for(auto v:brr){
                int g=gcd(u,v);
                if(cost[g]>cost[u]+1){
                    cost[g]=cost[u]+1;
                    q.push(g);
                }
            }
        }

        cout<<cost[glob]+n-1<<endl;
    }
return 0;
}