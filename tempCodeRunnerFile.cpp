uble t0=0.0;
        double y0=1.0;
        double h=0.1;
        double t_end=0.5;

        int steps=(t_end-t0)/h;
        double t=t0;
        double y=y0;

        for(int i=0;i<steps;i++){
            y=runge_kutta(t,y,h);
            t+=h;
        }
        cout<<y<<endl;