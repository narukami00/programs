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
        int n,m;
        cin>>n>>m;

        vector<int>cls(m);
        cin>>cls;

        sort(all(cls),[&](int x,int y){return (x/100)<(y/100);});

        int l=0,r=m-1;
        vector<vector<int>>sec(n,vector<int>(6));
        for(int i=1;i<n;i+=2){
            sec[i][0]=cls[l++];
            sec[i-1][0]=cls[r--];
        }

        for(int k=1;k<6;k++){
            for(int i=1;i<n;i+=2){
                sec[i][k]=sec[i-1][k-1];
                sec[i-1][k]=sec[i][k-1];
            }
        }

        if(n&1){
            for(int k=0;k<6;k++){
                if(k&1)sec[n-1][k]=cls[l];
                else sec[n-1][k]=cls[r];
            }
        }

        for(int i=0;i<n;i++){
            for(int k=0;k<6;k++){
                cout<<sec[i][k]<<sp;
            }
            cout<<endl;
        }

    }
return 0;
}