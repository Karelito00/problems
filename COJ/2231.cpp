#include <iostream>

using namespace std;

int main()
{
    int a,s1=0,s2=0;
    cin>>a;
    for(int b=0;b<a;b++){
        string j1,j2;
        cin>>j1>>j2;
        if(j1=="rock" && j2=="scissors")
            s1++;
        if(j1=="paper" && j2=="rock")
            s1++;;
        if(j1=="scissors" && j2=="paper")
            s1++;
        if(j2=="rock" && j1=="scissors")
            s2++;
        if(j2=="paper" && j1=="rock")
            s2++;
        if(j2=="scissors" && j1=="paper")
            s2++;
    }
    if(s1>s2)
        cout<<"A win";
    if(s1<s2)
        cout<<"B win";
    if(s1==s2)
        cout<<"tied";
    return 0;
}