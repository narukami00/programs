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
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        int posx=0,posy=0;
        for(char it:s){
            if(it=='D'){
                int sum=0;
                for(int i=0;i<m;i++){
                    sum+=arr[posx][i];
                }
                arr[posx][posy]=-sum;
                posx++;
            }else{
                int sum=0;
                for(int i=0;i<n;i++){
                    sum+=arr[i][posy];
                }
                arr[posx][posy]=-sum;
                posy++;
            }
        }
        int sum=0;
        for(int i=0;i<m;i++){
            sum+=arr[n-1][i];
        }
        arr[n-1][m-1]=-sum;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }
return 0;
}