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
        cout << it;
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
void solve(){
    int n,m,k,f=0,f1=0;
        cin>>n>>m>>k;
        vector<int> a(m),b(k);
        map<int,int> mp;
        vector<char> s;
        cin>>a;

        for(int i=0;i<k;i++){
            cin>>b[i];
            mp[b[i]]++;
        }

        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if(!mp[j] && j!=i ){
        //             f=1;
        //             break;
        //         }
        //         f=0;
        //     }

        //     if(f){
        //         if(!f1){
        //             s='0';
        //             f1=1;
        //         }
        //         else s+='0';
        //     }
        //     else{
        //         if(!f1){
        //             s='1';
        //             f1=1;
        //         }
        //         else s+='1';
        //     }
        // }
        int pos=-1;
        if(n==k){
            for(int i=0;i<m;i++)cout<<"1";
            cout<<endl;
            return;
        }

        if(k<=n-2){
            for(int i=0;i<m;i++)cout<<"0";
            cout<<endl;
            return;
        }

        if(k==n-1){
            for(int i=0;i<m;i++){
                if(!mp[a[i]]){
                    pos=i;
                    break;
                }
            }
            for(int i=0;i<m;i++){
                if(pos==i)s.push_back('1');
                else s.push_back('0');
            }

            cout<<s<<endl;
            return;
        }

}
int32_t main(){
    Flashyy
    tc
    {
        solve();
    }
return 0;
}