#include <bits/stdc++.h>

using namespace std;

int comp(string n){
    int sum = 0;
    for(int j=0;j<(int)n.size();j++)
        if(n[j] == ' ')
            sum++;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    string s;
    getline(cin,s);
    while(t--){
        getline(cin,s);
        string x;
        int con = comp(s);
        int ir = 0;
        for(int i=0;i<(int)s.size();i++){
            if(con > 0){
                if(i == 0){
                    if(s[i]>='a' && s[i]<='z')
                        x.push_back(char(s[i]-32));
                    else
                        x.push_back(s[i]);
                    x.push_back('.');
                    x.push_back(' ');
                    con--;
                }
                else if(s[i] == ' '){
                    i++;
                    if(s[i]>='a' && s[i]<='z')
                        x.push_back(char(s[i]-32));
                    else
                        x.push_back(s[i]);
                    x.push_back('.');
                    x.push_back(' ');
                    con--;
                }
            }
            else{
                for(int j=i;j<(int)s.size();j++)
                if(s[j] == ' '){
                    ir = j + 1;
                    break;
                }
                break;
            }
        }
        if(s[ir]>='a' && s[ir]<='z')
            x.push_back(char(s[ir]-32));
        else
            x.push_back(s[ir]);
        for(int i=ir+1;i<(int)s.size();i++){
            if(s[i]>='A' && s[i]<='Z')
                x.push_back(char(s[i]+32));
            else
                x.push_back(s[i]);
        }
        cout<<x<<"\n";
    }
    return 0;
}
