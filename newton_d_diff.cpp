#include<bits/stdc++.h>
using namespace std;
double newton(double x[],double y[],int n,double xp)
{
    double diff[n][n];
    for(int i=0; i<n; i++)diff[i][0]=y[i];
    for(int j=1; j<n; j++)
    {
        for(int i=0; i<n-j; i++)
        {
            diff[i][j]=(diff[i+1][j-1]-diff[i][j-1])/(x[i+j]-x[i]);
        }
    }
    double result=diff[0][0];
    double term=1.0;
    for(int i=0; i<n-1; i++)
    {
        term*=(xp-x[i]);
        result+=term*diff[0][i+1];

    }
    return result;
}
int main()
{
    int n;
    cin>>n;
    double true_;
    cin>>true_;
    double x[n],y[n];
    for(int i=0; i<n; i++)cin>>x[i]>>y[i];
    double xp;
    cin>>xp;
    double yp=newton(x,y,n,xp);
    cout<<fixed<<setprecision(6);
    cout<<yp<<endl;
    double et=fabs((true_-yp)/true_)*100;
    cout<<et<<endl;
}
