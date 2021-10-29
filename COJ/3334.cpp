#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin>>a;
    string s;
    cin>>s;
    int b;
    cin>>b;
    string p;
    cin>>p;
    string nuevo;
    int con=0;
    for(int k=0;k<s.size();k++){
        if(s[k]==p[con]){
            nuevo.push_back(s[k]);
            con++;
            if(con==p.size())
                con=0;
        }
    }

    if((int)(nuevo.size())/b>=1){
        cout<<(int)s.size()-(int)nuevo.size()+((int)nuevo.size()%b);
    }
    else
        cout<<-1;
    return 0;
}
