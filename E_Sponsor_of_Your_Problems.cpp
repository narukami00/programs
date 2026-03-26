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
        string l,r;
        cin>>l>>r;
        int n=sz(l);

        int ans=0;
        int i=0;

        while(i<n && l[i]==r[i]){
            ans+=2;
            i++;
        }

        if(i==n){
            cout<<ans<<endl;
            continue;
        }

        if(r[i]-l[i]>=2){
            cout<<ans<<endl;
        }else{
            int costl=1,costr=1;
            int j=i+1;
            while(j<n && l[j]=='9'){
                costl++;
                j++;
            }
            j=i+1;
            while(j<n && r[j]=='0'){
                costr++;
                j++;
            }
            cout<<ans+min(costl,costr)<<endl;
        }
    }
return 0;
}