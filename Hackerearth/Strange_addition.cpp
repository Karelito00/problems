    #include <bits/stdc++.h>
     
    using namespace std;
     
    int proc(string s){
        int num = 0;
        for(int i=0;i<(int)s.size();i++){
            num = (num * 10) + s[i] - '0';
        }
        return num;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            int n,m;
            cin>>n>>m;
            string s1;
            while(n > 0){
                s1.push_back((n%10)+'0');
                n/=10;
            }
            int num1 = proc(s1);
            string s2;
            while(m > 0){
                s2.push_back((m%10)+'0');
                m/=10;
            }
            int num2 = proc(s2);
            int suma = num1 + num2;
            string s3;
            while(suma > 0){
                s3.push_back((suma%10)+'0');
                suma/=10;
            }
            cout<<proc(s3)<<"\n";
        }
        return 0;
    }
