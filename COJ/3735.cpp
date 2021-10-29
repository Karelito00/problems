#include <bits/stdc++.h>

using namespace std;
int z[26];
int letras[26];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        int n;
        cin>>n;
        int hj=30;
        for(int y=0;y<n;y++){
            char c;
            cin>>c;
            z[c-'A']+=1;
            if(hj>c-'A')
                hj=c-'A';
        }
        char medio='*';
        int c=0;
        for(int u=hj;u<26;u++){
            if(c==0 && z[u]%2!=0){
                c++;
                medio=u+'A';
                z[u]--;
            }if(z[u]/2>=0){
                letras[u]=z[u]/2;
            }
        }
        string correct;
        for(int j=hj;j<26;j++){
            while(letras[j]!=0){
                correct.push_back(j+'A');
                letras[j]--;
            }
            }

        string ka=correct;
        reverse(ka.begin(),ka.end());
        if(c!=0)
            cout<<correct<<medio<<ka<<"\n";
        else
            cout<<correct<<ka<<"\n";
        memset(z,0,sizeof z);
        memset(letras,0,sizeof letras);
    }
    return 0;
}
