#include <bits/stdc++.h>

using namespace std;

int binary_karel(string h){
    int suma=0;
    reverse(h.begin(),h.end());
    for(int i=0;i<3;i++){
        suma+=(pow(2,i)*(h[i]-'0'));
    }
    return suma;
}

int main()
{
    string s;
    cin>>s;

    if(s.size()%3==0){
            int n=s.size();
        for(int u=0;u<n/3;u++){
            string j=s.substr(0,3);
            s.erase(0,3);
            cout<<binary_karel(j);
        }
    }
    else if(s.size()%3==1){
            int n=s.size();
            cout<<pow(2,0)*(s[0]-'0');
            s.erase(0,1);
        for(int i=0;i<n/3;i++){
            string j=s.substr(0,3);
            s.erase(0,3);
            cout<<binary_karel(j);
            }
    }
    else if(s.size()%3==2){
            int n=s.size();
            cout<<(pow(2,1)*(s[0]-'0'))+(pow(2,0)*(s[1]-'0'));
            s.erase(0,2);
        for(int i=0;i<n/3;i++){
            string j=s.substr(0,3);
            s.erase(0,3);
            cout<<binary_karel(j);
            }
    }
    return 0;
}
