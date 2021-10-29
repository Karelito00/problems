#include <iostream>

using namespace std;
char a1[]={'A','R','O','P','D','Q'};
int main()
{
    string s;
    cin>>s;
    int con=0;
    for(int x=0;x<s.size();x++){
        if(s[x]=='B')
            con+=2;
        else{
            for(int h=0;h<=5;h++){
                if(s[x]==a1[h]){
                    con++;
                break;
                }
            }
        }
    }
    cout<<con;
    return 0;
}