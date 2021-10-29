#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l;
    cin>>l;
    for(int b=0;b<l;b++){
    string s;
    cin>>s;
    int n;
    cin>>n;
    int g=s.size()-1;
    while(n>0){
        g--;
        if(g==-1)
            g=s.size()-1;
        n--;
    }
    for(int h=g+1;h<s.size();h++)
        cout<<s[h];
    for(int r=0;r<g+1;r++)
        cout<<s[r];
    cout<<"\n";
    }
    return 0;
}
