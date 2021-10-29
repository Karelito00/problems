#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,f1,f2;
    cin>>s;
    int suma=0,con1=0,con2=0;
    for(int y=0;y<s.size();y++){
        suma+=(s[y]-'A'+1);
    }
    con1=suma/2;
    con2=suma-con1;
    while(con1>0){
        if(con1>26){
            f1.push_back('Z');
            con1-=26;
        }
        else{
            f1.push_back(con1+'A'-1);
            con1=0;
        }
    }
    while(con2>0){
        if(con2>26){
            f2.push_back('Z');
            con2-=26;
        }
        else{
            f2.push_back(con2+'A'-1);
            con2=0;
        }
    }
    cout<<f1<<" "<<f2;
    return 0;
}
