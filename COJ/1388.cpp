#include <bits/stdc++.h>

using namespace std;

vector <int> digit[9];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    digit[0].push_back(4);
    digit[0].push_back(8);
    digit[0].push_back(6);
    digit[0].push_back(2);
    digit[1].push_back(9);
    digit[1].push_back(7);
    digit[1].push_back(1);
    digit[1].push_back(3);
    digit[2].push_back(6);
    digit[2].push_back(4);
    digit[3].push_back(5);
    digit[4].push_back(6);
    digit[5].push_back(9);
    digit[5].push_back(3);
    digit[5].push_back(1);
    digit[5].push_back(7);
    digit[6].push_back(4);
    digit[6].push_back(2);
    digit[6].push_back(6);
    digit[6].push_back(8);
    digit[7].push_back(1);
    digit[7].push_back(9);
    int a;
    cin>>a;
    for(int b=0;b<a;b++){
        string n;
        int v;
        cin>>n>>v;
        int c=3;
        int l=n[n.size()-1]-'0';
        if(v==0){
           cout<<1<<"\n";
        }
        else if(v==1)
            cout<<n[n.size()-1]<<"\n";
        else if(n[n.size()-1]=='2' || n[n.size()-1]=='3' || n[n.size()-1]=='7' || n[n.size()-1]=='8'){
           if(v>=4){
           int p=(v+2)%4;
            for(int i=-1;i<p;i++){
                c++;
                if(c==4)
                    c=0;
            }
           }else
             c = v-2;
        }
        else if(n[n.size()-1]=='4' || n[n.size()-1]=='9'){
                c=2;
                if(v>2){
                int p=v%2;
            if(c==2)
                c=0;
            for(int i=0;i<p;i++){
              c++;
              if(c==2)
                c=0;
            }
                }
                else
                    c=v-2;
        }
        else if(n[n.size()-1]=='5'){
                cout<<5<<"\n";
        }
        else if(n[n.size()-1]=='6'){
                cout<<6<<"\n";
        }
        else if(n[n.size()-1]=='0'){
            cout<<0<<"\n";
        }
        else if(n[n.size()-1]=='1')
            cout<<1<<"\n";
        if(v!=0 && v!=1 && n[n.size()-1]!='5' && n[n.size()-1]!='6' && n[n.size()-1]!='0' && n[n.size()-1]!='1')
        cout<<digit[l-2][c]<<"\n";
    }
    return 0;
}
