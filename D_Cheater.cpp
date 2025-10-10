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

int fun(int n,vector<int>a,vector<int>b){
    deque<int>qa(all(a));
    deque<int>qb(all(b));
    int mx=0;
    for(int i=0;i<n;i++){
        int ca=qa.front();qa.pop_front();
        int cb=qb.front();qb.pop_front();

        if(ca>cb){
            mx++;
            qb.push_front(cb);
        }else{
            qa.push_front(ca);
        }
    }
    return mx;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        cin>>a;cin>>b;

        int mx=fun(n,a,b);
        vector<vector<int>>dif;
        for(int i=0;i<n;i++){
            dif.pb({abs(a[i]-b[i]),i,a[i]});
        }sort(rall(dif));

        for(int i=0;i<min(100ll,n);i++){
            for(int j=0;j<min(100ll,n) && j<n;j++){
                vector<int>temp=a;
                swap(temp[dif[i][1]],temp[dif[j][1]]);
                mx=max(mx,fun(n,temp,b));
            }
        }

        cout<<mx<<endl;
    }
return 0;
}