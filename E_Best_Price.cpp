#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
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
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int rsum(int x, int y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n),b(n);
        cin>>a;
        cin>>b;
        vector<pair<int,int>> event;
        for(int i=0;i<n;i++){
            event.push_back(make_pair(a[i],1));
            event.push_back(make_pair(b[i],2));
        }
        sort(all(event));
        int ans=0;
        int c=n,nig=0;
        for(int i=0;i<n*2;){
            int x=event[i].first;
            if(nig<=k)ans=max(ans,x*c);
            while(i<2*n && event[i].first==x){
                nig+=(event[i].second==1);
                nig-=(event[i].second==2);
                c-=(event[i].second==2);
                i++;
            }
        }
        cout<<ans<<endl; 
    }
return 0;
}