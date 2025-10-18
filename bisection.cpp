#include<bits/stdc++.h>
using namespace std;

struct BisectionParameters{
    double tol_x=1e-8;
    double tol_rel=1e-8;
    double tol_f=1e-10;
    int max_iter=100;
    bool verbose=false;
};

template<typename F>bool Bisection(F f, double a, double b, double& root, string& reason, const BisectionParameters& p){
    double fa=f(a),fb=f(b);

    if(!isfinite(fa) || !isfinite(fb)){
        reason="Function not finite at the interval endpoints.";
        return false;
    }

    if(fa*fb>0){
        reason="No sign change in the interval.";
        return false;
    }

    double prev_c=a;
    for(int iter=1;iter<=p.max_iter;iter++){
        double c=0.5*(a+b);
        double fc=f(c);

        if(p.verbose)
            cout<<"Iter "<<iter<<": a="<<a<<" b="<<b<<" c="<<c<<" f(c)="<<fc<<endl;
        // Stopping conditions
        if(fabs(fc)<p.tol_f){
            root=c;
            reason="Function value close enough to zero.";
            return true;
        }
        if(fabs(b-a)<p.tol_x){
            root=c;
            reason="Interval width below absolute tolerance.";
            return true;
        }
        if(fabs(b-a)<p.tol_rel*fabs(c)){
            root=c;
            reason="Interval width below relative tolerance.";
            return true;
        }
        if(fabs(c-prev_c)<1e-14){
            root=c;
            reason="Stagnation detected (no progress).";
            return true;
        }

        // Normal bisection update
        if(fa*fc<0){
            b=c;
            fb=fc;
        } else {
            a=c;
            fa=fc;
        }

        prev_c=c;
    }

    root=0.5*(a+b);
    reason="Maximum iterations reached.";
    return true;
}    

template<typename F> void find_all_roots(F f, double start, double end, double step, const BisectionParameters& p){
    vector<double>roots;
    double a=start;
    double fa=f(a);

    for(double b=a+step;b<=end;b+=step){
        double fb=f(b);

        if(!isfinite(fa) || !isfinite(fb)){
            cout<<"Discontinuity detected between "<<a<<" and "<<b<<endl;
        }

        else if(fa*fb<0){
            double root;
            string reason;
            if(Bisection(f,a,b,root,reason,p)){
                cout << "Root found at x = " << root << " between [" << a << ", " << b << "] | " << reason << endl;
                roots.push_back(root);
            }
        }

        fa=fb;
        a=b;

        if(roots.size()>=10)break;
    }

    if (roots.empty())
        cout << "No roots found in given interval.\n";
    cout << endl;
}

int main(){
    auto f1=[](double x){return x*x-2.0;};
    auto f2=[](double x){return x*x-2*sin(x)-3;};
    auto f3=[](double x){return x*x-x*log(x)-5;};
    auto f4=[](double x){return tan(x)-3*x;};

    BisectionParameters params;

    cout<<"Finding roots for f1(x)=x^2-2 in [0,2]"<<endl;
    find_all_roots(f1,0,2,0.5,params);
    cout<<"Finding roots for f2(x)=x^2-2sin(x)-3 in [-4,4]"<<endl;
    find_all_roots(f2,-4,4,0.5,params);
    cout<<"Finding roots for f3(x)=x^2 - x*log(x)-5 in [0,4]"<<endl;
    find_all_roots(f3,0,4,0.5,params);
    cout<<"Finding roots for f4(x)=tan(x)-3x in [-10,10]"<<endl;
    find_all_roots(f4,-10,10,0.01,params);

    return 0;
}