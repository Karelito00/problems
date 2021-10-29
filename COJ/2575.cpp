#include <bits/stdc++.h>

using namespace std;

int p[501];
bool mar[501];
pair <int,int> sets[501];

int find_set(int x){
    if(p[x]==x)
        return x;
    return p[x]=find_set(p[x]);
}

void union_set(int y,int x){
    int set1=find_set(y),set2=find_set(x);
    if(sets[set1].second>sets[set2].second){
        p[set2]=set1;
        sets[set1].first+=sets[set2].first;
        sets[set1].first++;
        sets[set1].second+=sets[set2].second;
    }
    else{
        p[set1]=set2;
        sets[set2].first+=sets[set1].first;
        sets[set2].first++;
        sets[set2].second+=sets[set1].second;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int con=1;
    while(1){
        int n,m;
        cin>>n>>m;
        if(n==m && n==0)
            exit(0);
        for(int i=1;i<=n;i++)
            p[i]=i,sets[i].second=1;
        for(int h=0;h<m;h++){
            int n1,n2;
            cin>>n1>>n2;
            int setn1=find_set(n1),setn2=find_set(n2);
            if(setn1!=setn2){
                union_set(setn1,setn2);
            }
            else{
                sets[setn1].first++;
            }
        }
        int tra=0;
        for(int x=1;x<=n;x++){
            int hh=find_set(x);
            if(mar[hh]==false){
                mar[hh]=true;
                if(sets[hh].second-1==sets[hh].first){
                    tra++;
                }
            }
        }
        cout<<"Case "<<con<<": ";
        if(tra==1){
            cout<<"There is one tree.\n";
        }
        else if(tra==0){
            cout<<"No trees.\n";
        }
        else
            cout<<"A forest of "<<tra<<" trees.\n";
        con++;
        memset(mar,0,sizeof mar);
        memset(sets,0,sizeof sets);
    }
    return 0;
}
