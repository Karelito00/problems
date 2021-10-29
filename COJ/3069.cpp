#include <bits/stdc++.h>

using namespace std;

struct karel{
    string name;
    int edad;
    char sex;
    int id;
    karel(string name1, int edad1, char sex1,int id1){
        name = name1;
        edad = edad1;
        sex = sex1;
        id = id1;
    }
    bool operator < (const karel& hola)const{
        if(hola.name != name)
            return hola.name > name;
        return id < hola.id;
    }
};

vector < karel > para;
map < string , int > mapa;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        int edad;
        char x,x1,sex;
        cin>>s>>x>>edad>>x1>>sex;
        para.push_back(karel(s,edad,sex,i));
        mapa[s]++;
    }
    sort(para.begin(),para.end());
    int q1,q2;
    cin>>q1>>q2;
    for(int i=0;i<q1;i++){
        string t;
        cin>>t;
        cout<<mapa[t]<<"\n";
    }
    for(int i=0;i<q2;i++){
        int k;
        cin>>k;
        k--;
        cout<<para[k].name<<" : "<<para[k].edad<<" : "<<para[k].sex<<"\n";
    }
    return 0;
}
