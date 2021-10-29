#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char ini,fin;
    cin>>ini>>fin;
    int n;
    cin>>n;
    int mod = n % 4;
    char cw = ini, ccw = ini;
    while(mod > 0){
        if(cw == '<')
            cw = '^';
        else if(cw == '^')
            cw = '>';
        else if(cw == '>')
            cw = 'v';
        else if(cw == 'v')
            cw = '<';

        if(ccw == '<')
            ccw = 'v';
        else if(ccw == '^')
            ccw = '<';
        else if(ccw == '>')
            ccw = '^';
        else if(ccw == 'v')
            ccw = '>';
        mod--;
    }
    if(ccw == cw)
        cout<<"undefined";
    else if(ccw == fin)
        cout<<"ccw";
    else
        cout<<"cw";
    return 0;
}
