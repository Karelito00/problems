#include <bits/stdc++.h>

using namespace std;
string s[10000];
int main()
{
    int a;
    cin>>a;
    int j=0;
    double u=0;
    for(int b=0;b<a;b++){
        double puntadit,juegjug,goals,assis,ta,tr;
        cin>>s[b]>>puntadit>>juegjug>>goals>>assis>>ta>>tr;
        double f=log10(puntadit)+juegjug+(2*goals)+assis-(ta+(2*tr));
        if(f>u){
            j=b;
            u=f;
        }
    }
    cout<<s[j];
    return 0;
}
