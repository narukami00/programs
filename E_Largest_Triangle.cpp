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

double tri_area(double x1,double y1,double x2,double y2,double x3,double y3) {
    return 0.5*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
}


pair<double,double> intersect(double x1,double y1,double x2,double y2,double x0,double y0,double x_end) {
    double m=(y2-y1)/(x2-x1);
    double b=y1-m*x1;
    double x_intersect=(y0-b)/m;

    if(x_intersect<x0)x_intersect=x0;
    if(x_intersect>x_end)x_intersect=x_end;

    return {x_intersect,y0};
}


double solve(const vector<pair<double, double>>& points) {
    int n=points.size();
    double maxArea=0.0;
    
    for (int i=1;i<n-1;++i) {
        double x0=points[0].first;
        double y0=points[0].second;
        double xn=points[n-1].first;
        double yn=points[n-1].second;
        double x2=points[i].first;
        double y2=points[i].second;

        for(int j=1;j<i;j++){
            double sl1=(y2-y0)/(x2-x0);
            double sl2=(y2-points[j].second)/(x2-points[j].first);
            if(sl2>sl1){
                x0=points[j].first;
                y0=points[j].second;
            }
        }

        for(int j=n-2;j>i;j--){
            double sl1=(yn-y2)/(xn-x2);
            double sl2=(points[j].second-y2)/(points[j].first-x2);
            if(sl2<sl1){
                xn=points[j].first;
                yn=points[j].second;
            }
        }
    
        if(x0!=points[0].first || y0!=points[0].second){
            auto [p1,p2]=intersect(x2,y2,x0,y0,points[0].first,points[0].second,points[n-1].first);
            double x0=p1;
            double y0=p2;
        }
        
        if(xn!=points[n-1].first || yn!=points[n-1].second){
            auto [p1,p2]=intersect(x2,y2,xn,yn,points[0].first,points[0].second,points[n-1].first);
            xn=p1;
            yn=p2;
        }

        double area=tri_area(x0,y0,x2,y2,xn,yn);
        //cout<<area<<endl;
        maxArea=max(maxArea,area);

    }

    return maxArea;
}

int32_t main() {
    Flashyy
    int n;
    cin>>n;
    vector<pair<double,double>> points(n);
    for(int i=0;i<n;++i) {
        cin>>points[i].first>>points[i].second;
    }
    double maxArea=solve(points);
    cout<<fixed<<setprecision(9)<<maxArea<<endl;

    return 0;
}
