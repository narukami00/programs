#include <iostream>

using namespace std;
class shape{
  protected:
    double a,b;
  public:
      shape(int n,int m){
        a=n;
        b=m;
      }
    virtual double area()=0;
};
class rectangle : public shape{
public:
    rectangle(int a,int b):shape(a,b){}
    double area(){
        return a*b;
    }
   void rectdraw(){
       cout<<"Reactangle drawing"<<endl;
   }
};
class triangle : public shape{
public:
    triangle(int a,int b):shape(a,b){}
    double area(){
        return 0.5*a*b;
    }
};
int main()
{
    shape* p[5];
    for(int i=0;i<5;i++){
        if(rand () %2==0){
            p[i]=new rectangle (15,20);
        }
        else
            p[i]=new triangle (15,20);
    }
    for(int i=0;i<5;i++){
        rectangle *r=dynamic_cast<rectangle*>(p[i]);
        if(r!=NULL){
            r->rectdraw();
            cout<<"rectangle area "<<r->area()<<endl;
        }
        else cout<<"triangle area "<<p[i]->area()<<endl;
        delete p[i];
    }
    return 0;
}

