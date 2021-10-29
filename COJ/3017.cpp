#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(getline(cin,s)){
            stack <int> pila;
        for(int y=0;y<(int)s.size();y++){
            if(s[y]>='0' && s[y]<='9'){
                int num=s[y]-'0';
                y++;
                while(s[y]>='0' && s[y]<='9'){
                    num=(num*10)+(s[y]-'0');
                    y++;
                }
                pila.push(num);
            }
            else if(s[y]=='*'){
                int l=pila.top();
                pila.pop();
                int l1=pila.top();
                pila.pop();
                pila.push(l*l1);
            }
            else if(s[y]=='+'){
                int l=pila.top();
                pila.pop();
                int l1=pila.top();
                pila.pop();
                pila.push(l+l1);
            }
            else if(s[y]=='-'){
                int l=pila.top();
                pila.pop();
                int l1=pila.top();
                pila.pop();
                pila.push(l1-l);
            }
        }
        cout<<pila.top()<<"\n";
    }
    return 0;
}
