#include <bits/stdc++.h>

using namespace std;

string rever(string s) {
    string n;
    for(int i=0;i<s.size();i++){
        if(s[i]!='(')
            n.push_back(s[i]);
        else{
            i++;
            string t;
            int con=1;
            while(con>0){
                if(s[i]=='(')
                   con++;
                if(s[i]==')')
                    con--;
                if(con==0)
                    break;
                t.push_back(s[i]);
                i++;
            }
            t = rever(t);
            reverse(t.begin(),t.end());
            n+=t;
        }
    }
    return n;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin,s);
    cout<<rever(s);

    return 0;
}
