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

struct Params{
    double tol_f=1e-3;
    double tol_x=1e-8;
    int max_iter=100;  
};

template<typename F>
bool secant(F f, double x0, double x1, double &root, int &iter_count, const Params &p){
    double f0=f(x0),f1=f(x1);
    for(int i=1;i<=p.max_iter;i++){
        
        double x2=x1-f1*(x1-x0)/(f1-f0);
        double f2=f(x2);

        if(fabs(f2)<p.tol_f || fabs(x2-x1)<p.tol_x){
            root=x2;
            iter_count=i;
            return true;
        
        }

        x0=x1;
        f0=f1;
        x1=x2;
        f1=f2;
    }
    return false;
}

template<typename F>
void find_all(F f, double start, double end, double step, const Params &p){
    vector<pair<double,int>>roots;

    for(double a=start;a<=end-step;a+=step){
        double b=a+step;
        double root;
        int iter_count;
        if(secant(f,a,b,root,iter_count,p)){
            roots.pb({root,iter_count});
        }
    }

    sort(all(roots));
    roots.erase(unique(all(roots),[](pair<double,int>a,pair<double,int>b){return fabs(a.f-b.f)<1e-4;}),roots.end());

    cout<<"Roots found ("<<roots.size()<<")\n";
    for(int i=0;i<roots.size();i++){
        cout<<"  Root "<<i+1<<" = "<<roots[i].first<<" After "<<roots[i].second<<" iterations\n";
    }
    cout<<endl;
}

int32_t main(){
    Flashyy
    //tc
    {
        auto f=[](double x){return pow(x,4)-3*x*x*x+2*x*x+6*x;};
        Params p;
        double rng=sqrt(5);
        double step=0.5;
        find_all(f,-rng,rng,step,p);
    }
return 0;
}