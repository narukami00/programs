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

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int rsum(int x, int y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,l,r;
        cin>>n>>l>>r;
        int c=lcm(r,l);
        int x=n/l - n/c;
        int y=n/r - n/c;
        int s1=rsum(n-x+1,n);
        int s2=rsum(1,y);

        //for(int i=0;i<x;i++){s1+=n;n--;}
        //for(int i=0;i<y;i++){s2+=i+1;}
        /*
        int temp=1;
        int hudai=n;
        for(int i=0;i<hudai;i++){
            if(i<l){s1+=n;n--;}
            if(i<r){s2+=temp;temp++;}
            if(i>=l && i>=r)break;    
        }*/
       
        int sum=s1-s2;
        cout<<sum<<endl;
    }
return 0;
}