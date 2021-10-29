#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        string s;
        cin>>s;
        if(s=="end")
            break;
            int cons=0,t=0,l=0,tru=0;
        for(int y=0;y<s.size();y++){
            if(s[y]=='a' || s[y]=='e' || s[y]=='i' || s[y]=='o' || s[y]=='u'){
                cons=1;
            for(int u=y;u<y+3 && u<s.size();u++){
                if(s[u]=='a' || s[u]=='e' || s[u]=='i' || s[u]=='o' || s[u]=='u'){
                    l++;
                }else{
                    l=0;
                    break;
                }
            }
            }
            else{
            for(int u=y;u<y+3 && u<s.size();u++){
                if(s[u]=='a' || s[u]=='e' || s[u]=='i' || s[u]=='o' || s[u]=='u'){
                    t=0;
                    break;
                }
                t++;
            }
            }
            if(s[y]!='o' && s[y]!='e'){
                if(s[y]==s[y+1]){
                    tru++;
                    break;
                }
            }
            if(l==3 || t==3){
                tru++;
                break;
            }
                l=0;
                t=0;
        }
        if(cons==1 && tru==0)
            cout<<"<"<<s<<">"<<" is acceptable.\n";
        else
            cout<<"<"<<s<<">"<<" is not acceptable.\n";
    }
    return 0;
}
