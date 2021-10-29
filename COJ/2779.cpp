#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,k;
    cin>>a>>k;
    for(int i=0;i<k;i++){
        int s,d,p;
        cin>>s>>d>>p;
        int l=0,suma=0;
        while(l<a){
           int con=0;
           for(int i=1;i<=d;i++){
                if((i*s)+l>=a){
                    con=i;
                    break;
                }
                con=i;
           }
           l+=(con*s);
           suma+=con;
           if(l>=a)
            break;
           suma+=p;
        }
        cout<<suma<<"\n";
    }
    return 0;
}
