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
        
        vector<int>att(n+2),def(n+1),left(n+2),right(n+2),died;
        vector<bool>ded(n+1,0);
        set<int>may_die_set;

        att[0]=0;
        att[n+1]=0;
        for(int i=1;i<=n;i++){
            cin>>att[i];
            right[i]=i+1;
            left[i]=i-1;
            may_die_set.insert(i);
        }

        for(int i=1;i<=n;i++){
            cin>>def[i];
        }

        int rep=n;
        while(rep--){
            died.clear();
            for(int x:may_die_set){
                if(att[right[x]]+att[left[x]]>def[x]){
                    ded[x]=1;
                    died.pb(x);
                }
            }

            cout<<sz(died)<<sp;

            may_die_set.clear();
            for(int i=0;i<sz(died);i++){
                if(right[died[i]]<n+1 && !ded[right[died[i]]]){
                    may_die_set.insert(right[died[i]]);
                }
                if(left[died[i]]>0 && !ded[left[died[i]]]){
                    may_die_set.insert(left[died[i]]);
                }
            }

            for(int x:died){
                left[right[x]]=left[x];
                right[left[x]]=right[x];
            }
        }
        cout<<endl;
    }
return 0;
}