    #include <bits/stdc++.h>
     
    using namespace std;
     
    int mat[101][101];
    bool visited[101][101];
    int posx[] = {1,0,0,-1,1,-1,-1,1};
    int posy[] = {0,1,-1,0,1,1,-1,-1};
    int n;
     
    bool bfs(pair < int , int > pos , int num){
     
        queue < pair < int , int > > cola;
        cola.push(pos);
        while(!cola.empty()){
            int y1 = cola.front().first;
            int x1 = cola.front().second;
            cola.pop();
            for(int h=0;h<8;h++){
                int cy = posy[h], cx = posx[h];
                if(cy + y1>=0 && cy+y1 < n && cx + x1>=0 && cx + x1<n && mat[cy+y1][cx+x1] == num && visited[cy+y1][cx+x1]==false){
                    cola.push(make_pair(cy+y1,cx+x1));
                    visited[cy+y1][cx+x1] = true;
                }
            }
        }
        if(num == 1){
            for(int i=0;i<n;i++){
                if(visited[n-1][i]){
                    memset(visited, 0 , sizeof visited);
                    return true;
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(visited[i][n-1]){
                    memset(visited, 0 , sizeof visited);
                    return true;
                }
            }
        }
        memset(visited,0,sizeof visited);
        return false;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }
        pair < int , int > coor;
        bool flag1 = false, flag2 = false;
        for(int i=0;i<n;i++){
            if(mat[0][i] == 1){
                visited[0][i] = true;
                coor = make_pair(0,i);
                if(bfs(coor,1)){
                    flag1 = true;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0] == 2){
                coor = make_pair(i,0);
                visited[i][0] = true;
                if(bfs(coor,2)){
                    flag2 = true;
                    break;
                }
            }
        }
        if(flag1 && flag2)
            cout<<"AMBIGUOUS";
        else if(flag1)
            cout<<1;
        else if(flag2)
            cout<<2;
        else
            cout<<0;
        return 0;
    }
