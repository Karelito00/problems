#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string s;
        cin>>s;
        int jen=0,aln=0;
        int c=0,turn=0;
        for(int u=0;u<s.size();u++){
            while(s[u]==':'){
                c++;
                u++;
            }
            while(s[u]==')'){
                c++;
                u++;
            }
            u--;
            if(turn==0){
                turn=1;
                if(jen<c)
                    jen=c;
                c=0;
            }
            else if(turn==1){
                turn=0;
                if(aln<c)
                    aln=c;
                c=0;
            }
        }
        if(aln>jen)
            cout<<"Alan\n";
        else
            cout<<"Jennifer\n";
    }
    return 0;
}
