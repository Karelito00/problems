    #include <bits/stdc++.h>
    using namespace std;
     
    class karel{
    public:
        int id;
        long long punt;
        long long ant;
        karel(int id1,long long punt1,long long ant1){
            id = id1;
            punt = punt1;
            ant = ant1;
        }
        bool operator < (const karel& hola)const{
            if(hola.punt-hola.ant != punt-ant)
                return hola.punt-hola.ant < punt-ant;
            return hola.id < id;
        }
    };
    vector < karel > num;
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int id;
            long long z, p, l, c, s;
            cin>>id>>z>>p>>l>>c>>s;
            long long h=z;
            z = (50 * p);
            z += (l * 5);
            z += (c * 10);
            z += (s * 20);
            num.push_back(karel(id,z,h));
        }
        sort(num.begin(),num.end());
        for(int i=0;i<5;i++)
            cout<<num[i].id<<" "<<num[i].punt<<"\n";
        return 0;
    }
