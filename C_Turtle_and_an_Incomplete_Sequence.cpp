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

vector<int>path(int x,int y){
    vector<int>left,right;
    while(__lg(x)>__lg(y)){
        left.pb(x);
        x>>=1;
    }
    while(__lg(x)<__lg(y)){
        right.pb(y);
        y>>=1;
    }
    while(x!=y){
        left.pb(x);
        right.pb(y);
        x>>=1;
        y>>=1;
    }
    left.pb(x);
    reverse(all(right));
    for(int i:right)left.pb(i);
    return left;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>arr(n+1);
        int left=-1,right=-1;
        vector<int>given;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(arr[i]!=-1){
                if(left==-1)left=i;
                right=i;
                given.pb(i);
            }
        }

        if(left==-1){
            for(int i=1;i<=n;i++){
                cout<<(i&1)+1<<sp;
            }cout<<endl;
            continue;
        }

        for(int i=left-1;i>0;i--){
            arr[i]=((left-i)&1)?arr[left]*2:arr[left];
        }

        for(int i=right+1;i<=n;i++){
            arr[i]=((i-right)&1)?arr[right]*2:arr[right];
        }

        bool f=1;

        for(int i=1;i<sz(given);i++){
            int l=given[i-1],r=given[i];
            vector<int>p=path(arr[l],arr[r]);
            if((sz(p)&1)!=((r-l+1)&1) || (r-l+1)<sz(p)){
                f=0;
                break;
            }
            for(int j=0;j<sz(p);j++){
                arr[l+j]=p[j];
            }
            for(int j=l+sz(p),b=1;j<=r;j++,b^=1){
                arr[j]=(b?arr[j-1]*2:arr[j-1]/2);
            }
        }

        if(!f){
            cout<<-1<<endl;
            continue;
        }

        for(int i=1;i<=n;i++)cout<<arr[i]<<sp;
        cout<<endl;
    }
return 0;
}