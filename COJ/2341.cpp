#include <bits/stdc++.h>

using namespace std;

vector <string> correct;
int z[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int h=0;h<a;h++){
        string s;
        cin>>s;
        correct.push_back(s);
        cin>>z[h];
    }
    for(int i=0;i<b;i++){
        string m;
        cin>>m;
        int g;
        int c=0,p;
        for(int o=0;o<a;o++){
            if(correct[o]==m){
                c++;
                p=o;
                break;
            }
        }
        if(c!=0){
            cin>>g;
            if(g==z[p])
                cout<<"ok";
            else if(g!=z[p])
                cout<<"wrong";
        }
        else if(c==0)
            cout<<"not found";
        cout<<"\n";
    }
    return 0;
}
