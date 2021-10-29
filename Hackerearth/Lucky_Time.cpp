    #include <bits/stdc++.h>
     
    using namespace std;
     
    bool compr(int n,int n1,int n2){
        vector <int> num;
        if(n == 0)
            num.push_back(0),num.push_back(0);
        else if(n<10)
            num.push_back(0);
        while(n>0){
            num.push_back(n%10);
            n /= 10;
        }
        if(n1==0)
            num.push_back(0),num.push_back(0);
        else if(n1<10)
            num.push_back(0);
        while(n1>0){
            num.push_back(n1%10);
            n1 /= 10;
        }
        if(n2==0)
            num.push_back(0),num.push_back(0);
        else if(n2<10)
            num.push_back(0);
        while(n2>0){
            num.push_back(n2%10);
            n2/=10;
        }
        sort(num.begin(),num.end());
        for(int i=1;i<num.size();i++)
            if(num[i] == num[i-1])
                return false;
        return true;
    }
    string conv(int n,int n1,int n2){
        string t;
        if(n<10){
            t.push_back('0');
            t.push_back(char(n+'0'));
        }
        else{
            char a = char((n%10)+'0');
            n/=10;
            t.push_back(char((n%10)+'0'));
            t.push_back(a);
        }
        t.push_back(':');
     
        if(n1<10){
            t.push_back('0');
            t.push_back(char(n1 +'0'));
        }
        else{
            char a = char((n1 % 10)+'0');
            n1/=10;
            t.push_back(char((n1 % 10)+'0'));
            t.push_back(a);
        }
        t.push_back(':');
     
        if(n2<10){
            t.push_back('0');
            t.push_back(char(n2 + '0'));
        }
        else{
            char a = char((n2% 10)+'0');
            n2/=10;
            t.push_back(char((n2%10)+'0'));
            t.push_back(a);
        }
        return t;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            string s;
            cin>>s;
            int hrs = 0, minu = 0, sec = 0;
            for(int i=0;i<2;i++)
                hrs = (hrs * 10) + (s[i] - '0');
            for(int i=3;i<=4;i++)
                minu = (minu * 10) + (s[i] - '0');
            for(int i=6;i<=7;i++)
                sec = (sec * 10) + (s[i] - '0');
            while(1){
                if(compr(hrs,minu,sec))
                    break;
                sec++;
                if(sec == 60){
                    sec = 0;
                    minu++;
                }
                if(minu == 60){
                    minu = 0;
                    hrs++;
                }
                if(hrs == 24)
                    hrs = 0;
            }
            cout<<conv(hrs,minu,sec)<<"\n";
        }
        return 0;
    }
