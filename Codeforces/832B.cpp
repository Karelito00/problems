#include <bits/stdc++.h>

using namespace std;

string n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t;
    cin>>t;
    sort(t.begin(),t.end());
    string s;
    cin>>s;
    int q;
    cin>>q;
    while(q--){
        cin>>n;
        int con = 0;
        bool flag = false;
        for(int j=0;j<(int)s.size();j++,con++){
            if(s[j] == '?'){
                if(binary_search(t.begin(),t.end(),n[con]))
                    continue;
                else{
                    flag = true;
                    break;
                }
            }
            if(s[j] == '*'){
                int dist = ((int)n.size() - con) - ((int)s.size()-j) + 1;
                if(dist < 0){
                    flag = true;
                    break;
                }
                if(dist == 0){
                    con--;
                    continue;
                }
                while(dist > 0){
                    if(binary_search(t.begin(),t.end(),n[con]) == true){
                        flag = true;
                        break;
                    }
                    con++;
                    dist--;
                }
                con--;
                if(flag)
                    break;
            }
            else if(s[j] != n[con]){
                flag = true;
                break;
            }
        }
        if(con == (int)n.size() && flag == false)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}