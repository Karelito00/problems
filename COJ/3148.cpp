#include <bits/stdc++.h>

using namespace std;
string z[9][9];
string x[9][9];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int k1;
    for(int i=1;i<=8;i++){
            if(i%2==0)
            k1=0;
            else
            k1=1;
        for(int j=0;j<8;j++){
            if(j%2!=k1){
            s="WHITE";
            x[i-1][j]=s;
            }
            else{
                s="BLACK";
                x[i-1][j]=s;
            }
        }
    }
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
          string s;
        if(j==0){
            s.push_back('a');
            s.push_back(i+1+'0');
        }
        if(j==1){
            s.push_back('b');
            s.push_back(i+1+'0');
        }
        else if(j==2){
            s.push_back('c');
            s.push_back(i+1+'0');
        }
        else if(j==3){
            s.push_back('d');
            s.push_back(i+1+'0');
        }
        else if(j==4){
            s.push_back('e');
            s.push_back(i+1+'0');
        }
        else if(j==5){
            s.push_back('f');
            s.push_back(i+1+'0');
        }
       else if(j==6){
            s.push_back('g');
            s.push_back(i+1+'0');
        }
       else if(j==7){
            s.push_back('h');
            s.push_back(i+1+'0');
        }
        z[i][j]=s;
      }

    }
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string o;
        cin>>o;
        int m=0,l1,l2;
    for(int h=0;h<8;h++){
        for(int g=0;g<8;g++){
            if(z[h][g]==o){
               l1=h;
               l2=g;
               m=1;
               break;
            }
     }
             if(m==1)
                break;
    }
    cout<<x[l1][l2]<<"\n";
    }

    return 0;
}
