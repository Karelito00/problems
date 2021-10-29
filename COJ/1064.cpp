#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        int h1,m1,h2,m2;
        cin>>h1>>m1>>h2>>m2;
        if(h1==0 && m1==0 && h2==0 && m2==0)
            break;
        int con=0;
        while(h1!=h2 || m1!=m2){
            m1++;
            if(m1==60){
                m1=0;
                h1++;
                if(h1==24)
                    h1=0;
            }
            con++;
        }
        cout<<con<<"\n";
    }
    return 0;
}
