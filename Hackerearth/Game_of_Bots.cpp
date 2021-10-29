    #include <bits/stdc++.h>
    using namespace std;
     
    int A[10000001];
    int B[10000001];
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            string x,x1;
            cin>>x>>x1;
            int cona=0, conb=0;
            for(int i = 0;i < (int)x.size();i++){
                if(x[i]=='A')
                    A[cona] = i,cona++;
                else if(x[i]=='B')
                    B[conb] = i,conb++;
            }
            int conta = 0, contb = 0;
            bool flag = false;
            for(int i=0;i<(int)x1.size();i++){
                if(x1[i]=='A'){
                    if(i > A[conta]){
                        flag = true;
                        break;
                    }
                    conta++;
                }
                else if(x1[i]=='B'){
                    if(i < B[contb]){
                        flag = true;
                        break;
                    }
                    contb++;
                }
            }
            if(conta!=cona || contb!=conb){
                cout<<"No\n";
                continue;
            }
            if(flag)
                cout<<"No\n";
            else
                cout<<"Yes\n";
        }
        return 0;
    }
