#include <bits/stdc++.h>

using namespace std;

char z[28];
int m;
string s;
string new_string(string y){
    reverse (y.begin(),y.end());
    for(int x=0;x<y.size();x++){
        for(int u=0;u<28;u++){
            if(z[u]==y[x]){
                if(u+m<=27){
                    y[x]=z[u+m];
                }else{
                int j=(u+m)-28;
                y[x]=z[j];
                }
                break;
            }
        }
    }
    return y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n=17;
    for(int i=0;i<26;i++){
        z[i]=n+'0';
        n++;
    }
    z[26]='_'; z[27]='.';
    while(1){
        cin>>m;
        if(m==0)
            break;
        cin>>s;
       cout<<new_string(s)<<"\n";
    }
    return 0;
}
