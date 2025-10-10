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
        vector<int> a(n),b(n);
        cin>>a;
        cin>>b;

        int f=1;
        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                f=0;
                break;
            }
        }
        if(!f){
            no;
            continue;
        }

        for(int i=0;i<n;i++){
            if(a[i]==b[i])continue;

            int need=b[i];
            bool fseg=0;

            for(int j=i-1;j>=0;j--){
                if(a[j]==need){
                    bool val=1;
                    for(int k=j;k<=i;k++){
                        if(a[k]>need){val=0;break;}
                        if(b[k]<need){val=0;break;}
                    }
                    if(val){
                        fseg=1;
                        break;
                    }
                }
            }

            for(int j=i+1;j<n && !fseg;j++){
                if(a[j]==need){
                    bool val=1;
                    for(int k=i;k<=j;k++){
                        if(a[k]>need){val=0;break;}
                        if(b[k]<need){val=0;break;}
                    }
                    if(val){
                        fseg=1;
                        break;
                    }
                }
            }

            if(!fseg){
                f=0;
                break;
            }
       }
       if(f)yes;
       else no;
    }
return 0;
}