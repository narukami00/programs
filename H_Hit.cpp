#include <bits/stdc++.h>
using namespace std;
typedef double ll;
#define dl double

int main()
{

    ll t;
    // cin >> t;
    // t = 1;
    // while (t--)
    {

        ll a, b, c, d, x, y, m, n;

        cin >> a >> b >> x >> c >> d >> y;
    
        // m = x;
        ll ds = sqrt((a - c) * (a - c) + (b - d) * (b - d));

        if(x>ds){
            cout<<c<<" "<<d<<endl;
            return 0;
        }
        else if(y>ds){
            cout<<a<<" "<<b<<endl;
            return 0;
        }
        dl left = ds-x;
        left= y-left;
        dl right_left=x-left/2.0;
        // cout<<x<< " " <<left<<endl;

        m=right_left;
        n = ds - m;
        //  cout <<m<<" "<<ds <<endl;
        
        x = a * n + c * m;
        x /= (ds);
        y = b * n + d * m;
        y /= (ds);

        cout << x << " " << y << endl;
    }
}

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// // #define double long double
// #define dl double
// #define endl '\n'
// #define no cout<<"NO\n"
// #define yes cout<<"YES\n"
// #define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define sp " "
// #define all(x) x.begin(), x.end()

// template <typename T> // cin >> vector<T>
// istream &operator>>(istream &istream, vector<T> &v)
// {
//     for (auto &it : v)
//         cin >> it;
//     return istream;
// }
// template <typename T> // cout << vector<T>
// ostream &operator<<(ostream &ostream, const vector<T> &c)
// {
//     for (auto &it : c)
//         cout << it << " ";
//     return ostream;
// }

// int gcd(int a, int b) {
//     while (b != 0) {
//         int tmp = a % b;
//         a = b;
//         b = tmp;
//     }
//     return a;
// }
// int lcm(int a, int b) {
//     return a * b / gcd(a, b);
// }

// int rsum(int x, int y){
//     if(x>y)return 0;
//     return (x+y)*(y-x+1)/2;
// }

// #define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

// double dis(int a, int b, int c, int d){
//     return sqrt(((a-c)*(a-c))+((b-d)*(b-d)));
// }

// double ta(dl delx,dl dely){
//     dl ret= atan(1.0*(dely)/(delx));
//     dl pi= acos(-1.0);
//     if(delx>=0 && dely>=0){
//         return ret;
//     }
//     else if(delx<0 && dely>=0){
//         return pi-ret;
//     }
//     else if(delx>=0 && dely<0){
//         return pi + ret;
//     }
//     else{
//         return -ret;
//     }
// }
// int32_t main(){
//     Flashyy
//     // tc
//     {
//         int x1,y1,r1,x2,y2,r2;
//         cin>>x1>>y1>>r1>>x2>>y2>>r2;

//         dl d= dis(x1,y1,x2,y2);

//         dl left = d-r1;
//         left= r2-left;
//         cout<<d<<" "<<left<<endl;
//         int dely =y1-y2;
//         int delx =x1-x2;
//         // dl theta=atan(1.0*(y1-y2)/(x1-x2));
//         dl theta= ta(delx,dely);
//         cout<<theta<<endl;

//         dl xnew=1.0*r1-left/2;
//         xnew=xnew*cos(theta);
//         xnew+=x1;
//         dl ynew= 1.0*r1-left/2;
//         ynew =ynew*sin(theta);
//         ynew+=y1;
//         cout<<xnew<<" "<<ynew<<endl;
//         dl pi= acos(-1.0);
//         cout<<pi<<endl;

//     }
// return 0;
// }