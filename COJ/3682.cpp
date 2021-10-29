#include <bits/stdc++.h>

using namespace std;


int main (){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
//  long double ar[3];
  for (int i = 0; i < n; i++){
    long double a,b,c;
    cin>>a>>b>>c;
    a/=1000;
    b/=1000;
    c/=1000;
    /*long double d =(b+c-a), f=a+b-c, m=c+a-b, l = a*b*c;
    ar[0] =d; ar[1] =f; ar[2] = m;
    sort(ar, ar+3);
    long double y= ar[2]/l, u = ar[1]*ar[0] *y;*/
    //u*=1000;
    long double y = ((b+c-a)*(a+b-c)*(c+a-b))/(a*b*c);
    //y*=100;
    //cout<<y<<"\n";
    if (y == 1)
        cout<<"equilateral\n";
    else if (y < 1 && y > 0.5)
        cout<<"good\n";
    else if (y <= 0.5 && y > 0)
        cout<<"bad\n";

    //cout<<u<<"\n";
  }

  return 0;
}
