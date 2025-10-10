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
        
        vector<int>b(n),a(n);
        int sum=0;
        for(int i=0;i<n;i++){cin>>b[i];sum+=b[i];}

        int d=n*(n+1)/2;
        if(sum%d!=0){
            no;
            continue;
        }

        bool f=1;
        int asum=sum/d;
        for(int i=n-1;i>=0;i--){
            int c=(b[i]-b[(i+1)%n]+asum);
            if(c%n!=0 || c<=0){
                f=0;
                break;
            }
            a[(i+1)%n]=c/n;
        }

        if(!f){
            no;
            continue;
        }

        yes;
        cout<<a<<endl;
    }
return 0;
}