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

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        vector<int>pos,neg,zero;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>0)pos.pb(arr[i]);
            if(arr[i]<0)neg.pb(arr[i]);
            if(arr[i]==0)zero.pb(arr[i]);
        }

        int need=*max_element(all(arr))-*min_element(all(arr));
        if(need==0){
            no;
            continue;
        }

        yes;
        for(int i=0;i<sz(zero);i++){cout<<zero[i]<<sp;}
        sort(all(pos));reverse(all(pos));
        sort(all(neg));reverse(all(neg));
        int k=0,l=0,lim=0;
        for(int i=0;i<sz(pos)+sz(neg);i++){
            if(lim<=0 && k<sz(pos)){
                cout<<pos[k]<<sp;
                lim+=pos[k];k++;
            }else if(l<sz(neg)){
                cout<<neg[l]<<sp;
                lim+=neg[l];l++;
            }else if(k<sz(pos)){
                cout<<pos[k]<<sp;
                k++;
            }
        }
        cout<<endl;
    }
return 0;
}