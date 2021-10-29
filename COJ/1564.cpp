#include <bits/stdc++.h>

using namespace std;
int main()
{
    while(1){
    float mayor_m=0, mayor_f=0;
    string mm, mf;
    int n;
    cin>>n;
    if (n == 0)
        break;
    for (int i = 0; i < n; i++){
        string a;
        cin>>a;
        char s;
        cin>>s;
        float h = 0, j = 0;
        cin>>h>>j;
        float o = 100-(j/h*100);
        if (s == 'M' && o > mayor_m){
            mayor_m = o;
            mm = a;
        }else if (s == 'F' && o > mayor_f){
            mayor_f = o;
            mf = a;
        }
    }
    cout<<mm<<" ";
    printf("%.2f",mayor_m);
    cout<<"% "<<mf<<" ";
    printf("%.2f",mayor_f);
    cout<<"%\n";
    }


    return 0;
}
