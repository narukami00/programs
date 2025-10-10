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
    //tc
    {
        string s[10];
        for(int i=0;i<10;i++){
            cin>>s[i];
        }
        int ans=0;
        vector<int> maxx;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(s[i][j]=='.'){
                    ans=8;
                    if(!(i-2>=0 && j-1>=0 && i-2<10 && j-1<10 && s[i-2][j-1]!='.')){
                        ans--;
                    }
                    if(!(i-2>=0 && j+1>=0 && i-2<10 && j+1<10 && s[i-2][j+1]!='.')){
                        ans--;
                    }
                    if(!(i+2>=0 && j-1>=0 && i+2<10 && j-1<10 && s[i+2][j-1]!='.')){
                        ans--;
                    }
                    if(!(i+2>=0 && j+1>=0 && i+2<10 && j+1<10 && s[i+2][j+1]!='.')){
                        ans--;
                    }
                    if(!(i-1>=0 && j-2>=0 && i-1<10 && j-2<10 && s[i-1][j-2]!='.')){
                        ans--;
                    }
                    if(!(i-1>=0 && j+2>=0 && i-1<10 && j+2<10 && s[i-1][j+2]!='.')){
                        ans--;
                    }
                    if(!(i+1>=0 && j-2>=0 && i+1<10 && j-2<10 && s[i+1][j-2]!='.')){
                        ans--;
                    }
                    if(!(i+1>=0 && j+2>=0 && i+1<10 && j+2<10 && s[i+1][j+2]!='.')){
                        ans--;
                    }
                }
                maxx.push_back(ans);
                ans=0;
            }
        }
        int maximum=*max_element(all(maxx));
        cout<<maximum<<endl;

    }
return 0;
}