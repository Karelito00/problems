#include <bits/stdc++.h>
#define mx(a,b) (a > b ? a : b)

using namespace std;

int best;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int con = 0, nuev = 0;
    int flag = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] != '_' && s[i] != '(' && s[i] != ')'){
            con++;
        }
        else{
            if(!flag)
                best = mx(best,con);
            else if(con != 0)
                nuev++;
            con = 0;
        }
        if(s[i] == '('){
            flag++;
            best = mx(best,con);
        }
        else if(s[i] == ')'){
            if(con != 0)
                nuev++;
            flag--;
        }
        if(s.size()-1 == i){
            if(!flag)
                best = mx(best,con);
            else
                nuev++;
        }
    }
    cout<<best<<" "<<nuev;
    return 0;
}
