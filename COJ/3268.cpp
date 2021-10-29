#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int con=1;
    int best=1,col=0;
    if(s[0]=='R')
        col=1;
    else if(s[0]=='M')
        col=2;
    else if(s[0]=='F')
        col=3;
    for(int u=1;u<s.size();u++){
        if(s[u]!=s[u-1]){
            if(con>best){
                best=con;
                if(s[u-1]=='M')
                    col=2;
                else if(s[u-1]=='R')
                    col=1;
                else if(s[u-1]=='F')
                    col=3;
            }
            else if(con==best){
                int n=0;
                if(s[u-1]=='R')
                    n=1;
                else if(s[u-1]=='M')
                    n=2;
                else if(s[u-1]=='F')
                    n=3;
                col=min(col,n);
            }
            con=0;
        }
        con++;
        if(u==s.size()-1){
            if(con>best){
                best=con;
                if(s[u]=='M')
                    col=2;
                else if(s[u]=='R')
                    col=1;
                else if(s[u]=='F')
                    col=3;
            }
            else if(con==best){
                int n=0;
                if(s[u]=='R')
                    n=1;
                else if(s[u]=='M')
                    n=2;
                else if(s[u]=='F')
                    n=3;
                col=min(col,n);
            }
            con=0;
        }
    }

    string k;
    if(col==1)
        k="Rat";
    else if(col==2)
        k="Milk";
    else if(col==3)
        k="Fish";
    cout<<best<<" "<<k;
    return 0;
}
