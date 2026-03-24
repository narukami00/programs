#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
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
        int n;
        cin>>n;
        vector<int>x(n);
        map<int,int>cnt;
        map<int,int>pos;
        for(int i=0;i<n;i++){
            cin>>x[i];
            cnt[x[i]]++;
            pos[x[i]]=i+1;
        }

        int absent=0;
        for(int i=1;i<=n;i++){
            if(cnt[i]==0)absent=i;
        }

        if(absent!=0){
            int y;
            if(absent>1)y=absent-1;
            else y=absent+1;

            cout<<"? "<<absent<<" "<<y<<endl;
            int z;
            cin>>z;
            if(z==0)cout<<"! A"<<endl;
            else cout<<"! B"<<endl;
        }else{
            cout<<"? "<<pos[1]<<" "<<pos[n]<<endl;
            int y;cin>>y;
            cout<<"? "<<pos[n]<<" "<<pos[1]<<endl;
            int z;cin>>z;

            if(y==z && y>=n-1)cout<<"! B"<<endl;
            else cout<<"! A"<<endl;
        }
    }
return 0;
}