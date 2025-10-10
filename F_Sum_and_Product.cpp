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
#define sz(x) x.size()
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

bool isSquare(int x, int &sq){
    if(x<0) return false;

    int l=0, r=5000000001;

    while(r-l>1){
        int mid=(l+r)/2;
        if(mid*mid<=x)l=mid;
        else r=mid;
    }

    if(l*l==x){
        sq=l;
        return true;
    }
    return false;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        int q;
        cin>>q;
        while(q--){
            int x,y,cnt=0;
            cin>>x>>y;
            
            int d=x*x-4*y;

            int sq;
            if(!isSquare(d,sq)){
                cout<<"0"<<sp;
                continue;
            }

            if((x+sq)%2!=0 || (x-sq)%2!=0){
                cout<<"0"<<sp;
                continue;
            }

            int r1=(x+sq)/2;
            int r2=(x-sq)/2;

            if(r1==r2){
                cnt=mp[r1]*(mp[r1]-1)/2;
            }else{
                cnt=mp[r1]*mp[r2];
            }

            cout<<cnt<<" ";
        }
        cout<<endl;
    }
return 0;
}