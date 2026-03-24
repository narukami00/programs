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
        int n;
        cin>>n;
        vector<int>x(n),y(n);
        multiset<int>a,b;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
            a.insert(x[i]);
            b.insert(y[i]);
        }

        int w=*a.rbegin()-*a.begin()+1;
        int h=*b.rbegin()-*b.begin()+1;
        int ans=w*h;
        
        for(int i=0;i<n;i++){
            a.erase(a.find(x[i]));
            b.erase(b.find(y[i]));

            if(a.empty() || b.empty()){
                a.insert(x[i]);
                b.insert(y[i]);
                continue;
            }

            w=*a.rbegin()-*a.begin()+1;
            h=*b.rbegin()-*b.begin()+1;
            ans=min(ans,w*h);
            
            if(ans==n-1){
                ans+=min(h,w);
            }

            a.insert(x[i]);
            b.insert(y[i]);
        }

        cout<<ans<<endl;
    }
return 0;
}