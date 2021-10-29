#include <bits/stdc++.h>

using namespace std;

char z[26];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        int f=0;
        for(int y=0;y<s2.size();y++){
                int con=0;
            for(int u=0;u<s1.size();u++){
               if(s2[y]==s1[u])
               con=1;
               }
        if(con!=1){
          f=1;
        break;
        }
        }
        for(int y=0;y<s3.size();y++){
                int con=0;
            for(int u=0;u<s1.size();u++){
               if(s3[y]==s1[u])
               con=1;
               }
        if(con!=1){
          f=1;
        break;
        }
        }
        for(int j=0;j<s2.size();j++){
            for(int t=j+1;t<s2.size();t++){
                if(s2[j]==s2[t])
                    f=1;
                if(f==1)
                    break;
            }
            if(f==1)
                    break;
        }
        for(int j=0;j<s3.size();j++){
            for(int t=j+1;t<s3.size();t++){
                if(s3[j]==s3[t])
                    f=1;
                if(f==1)
                    break;
            }
            if(f==1)
                    break;
        }
        for(int p=0;p<s2.size();p++){
            for(int o=0;o<s3.size();o++){
                if(s2[p]==s3[o])
                    f=1;
                if(f==1)
                    break;
            }
            if(f==1)
                break;
        }
        for(int k=0;k<s1.size();k++){
            for(int u=0;u<s2.size();u++){

            }
            for(int u=0;u<s3.size();u++){

            }
        }
        if(f==1)
            cout<<"CHEATER"<<"\n";
            else{
                    int mu=0;
               for(int j=0;j<s1.size();j++){
                    int w=0;
                for(int x1=0;x1<s2.size();x1++){
                  if(s1[j]==s2[x1]){
                  w=1;
                  break;
                  }
                }
                for(int x1=0;x1<s3.size();x1++){
                  if(s1[j]==s3[x1]){
                    w=1;
                    break;
                  }
                }
                if(w!=1){
                    z[mu]=s1[j];
            mu++;}
               }
               sort(z,z+mu);
               for(int j=0;j<mu;j++)
                    cout<<z[j];
                    cout<<"\n";
            }

    }
    return 0;
}
