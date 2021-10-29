#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e3 + 10;

struct companies{
    long long offered_salary;
    int jobs;
}works[MAXn];

bool taken_companies[MAXn];
long long min_salary[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,comp;
        cin>>n>>comp;
        for(int i = 0; i < n; i++)
            cin>>min_salary[i];
        for(int i = 0; i < comp; i++){
            cin>>works[i].offered_salary>>works[i].jobs;
        }
        int cand = 0;
        long long total_salary = 0;
        int compan = 0;
        for(int i=0;i<n;i++){
            long long best = -1;
            int index = 0;
            for(int j=0;j<comp;j++){
                char x;
                cin>>x;
                if(x == '1'){
                    if(works[j].jobs > 0 && works[j].offered_salary > best){
                        best =  works[j].offered_salary;
                        index = j;
                    }
                }
            }
            if(best != -1 && best >= min_salary[i]){
                cand++;
                total_salary += best;
                works[index].jobs--;
                if(!taken_companies[index])
                taken_companies[index] = true, compan++;
            }
        }
        cout<<cand<<" "<<total_salary<<" "<<comp-compan<<"\n";
        fill(taken_companies, taken_companies + comp, false);
    }
    return 0;
}
