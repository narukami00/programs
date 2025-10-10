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
        int m,a,b,c;
        int ans=0;
        cin>>m>>a>>b>>c;
        if(m>=a && m>=b){
            int rem =2*m-(a+b);
            if(rem==0)ans+=a+b;
            else if(rem>=c)ans+=a+b+c;
            else if(rem<=c)ans+=a+b+rem;
        }
        else if(m>=a && m<b){
            int rem1=m-a;ans+=a;
            if(rem1>=c)ans+=c;
            else if(rem1<c)ans+=rem1;

            ans+=m;
        }
        else if(m>=b && m<a){
            int rem1=m-b;ans+=b;
            if(rem1>=c)ans+=c;
            else if(rem1<c)ans+=rem1;

            ans+=m;
        }
        else if(m<a && m<b){
            ans+=2*m;
        }
    
        cout<<ans<<endl;

    }
return 0;
}