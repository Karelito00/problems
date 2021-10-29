#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,s,j,d;
    cin>>a>>s>>j>>d;
    string m;
    cin>>m;
    int j1=0,j2=0,s1=0,s2=0;
    for(int i=0;i<m.size();i++){
        if(m[i]=='A')
            j1++;
        else
            j2++;
        if(abs(j1-j2)>=d && (j1>=j || j2>=j)){
            if(j1>j2)
                s1++;
            else
                s2++;
            j1=0;
            j2=0;
        }
    }
    cout<<s1<<" "<<s2;
    return 0;
}
