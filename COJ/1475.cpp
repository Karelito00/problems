#include <bits/stdc++.h>

using namespace std;
int z[10000];
int main()
{
    //1475
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r=0,w=0;
    char a[100000];
    while(1){
        char s[500];
        gets(s);
        if(s[0]=='#')
            break;
        int u=strlen(s);
     int o=s[strlen(s)-1]-'A';
     for(int l=0;l<u-1;l++){
            int c=0;
        if((s[l]-'0'>=17 && s[l]-'0'<=42) || (s[l]-'0'>=49 && s[l]-'0'<=74)){
            if(s[l]-'0'>=17 && s[l]-'0'<=42){
            char f=s[l]-'A';
            if(f-o<0){
            s[l]=s[l]+26-o;
            c++;
            }
            }
            else if(s[l]-'0'>=49 && s[l]-'0'<=74){
            char f=s[l]-'a';
            if(f-o<0){
            s[l]=s[l]+26-o;
            c++;
            }
            }
            if(c==0)
            s[l]-=o;

        }
        a[r]=s[l];
        r++;
     }

     z[w]=u;
     w++;
    }
    int hn=0;
    for(int j=0;j<r;j++){
    if(z[hn]==1){
        cout<<"\n";
        hn++;
    }
    z[hn]--;
        cout<<a[j];
    }


        return 0;
}
