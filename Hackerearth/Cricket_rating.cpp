    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main()
    {
        int n;
        cin>>n;
        int bests=-100000,sum1=0,men=0;
        for(int y=0;y<n;y++){
            int t;
            cin>>t;
            sum1+=t;
            bests=max(bests,sum1-men);
            men=min(men,sum1);
        }
        (bests < 0 ? cout<<0 : cout<<bests);
        return 0;
    }
