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

int32_t main(){
    Flashyy
    tc
    {
        int n,c;
        cin>>n>>c;
        vector<int>arr(c+1,0);
        for(int i=0;i<n;i++){
            int x;cin>>x;arr[x]++;
        }
        if(!arr[1]){
            no;continue;
        }
        for(int i=1;i<=c;i++)arr[i]+=arr[i-1];
        bool f=1;
        for(int i=1;i<=c && f;i++){
            if(arr[i]!=arr[i-1]){
                for(int j=1;j*i<=c && f;j++){
                    if(arr[j]==arr[j-1] && arr[min(c,j*i+i-1)]!=arr[j*i-1]){
                        f=0;break;
                    }
                }
            }
        }
        if(f)yes;
        else no;
    }
return 0;
}