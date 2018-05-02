#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector <vector<int>> v1,v2;
int visited[51],finish[51],arr[51][2],cycle;

int dfs1(int cur,int cnt){
    visited[cur]=1;
    for(auto i : v1[cur]){
        if(!visited[i]) cnt=dfs1(i,cnt+1);
        if(!finish[i]) cycle=1;
    }
    finish[cur]=1;
    return cnt;
}

int dfs2(int cur,int cnt){
    visited[cur]=1;
    for(auto i : v2[cur]){
        if(!visited[i]) cnt=dfs2(i,cnt+1);
        if(!finish[i]) cycle=1;
    }
    finish[cur]=1;
    return cnt;
}

int main(){
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    int T,N,M,big,small;
    cin>>T;
    while(T--){
        memset(finish,0,sizeof(finish));
        v1.clear();
        v2.clear();
        cycle=0;
        cin>>N>>M;
        v1.resize(N+1);
        v2.resize(N+1);
        for(int i=0;i<M;i++){
            cin>>big>>small;
            v1[big].push_back(small);
            v2[small].push_back(big);
        }
        
        for(int i=1;i<=N;i++){
            memset(visited,0,sizeof(visited));
            if(!visited[i]){
                arr[i][0]=dfs1(i,0);
                arr[i][1]=dfs2(i,0);
                if(cycle==1)break;
            }
        }
        
        if(!cycle){
            for(int i=1;i<=N;i++){
                printf("%d %d\n",arr[i][1],arr[i][0]);
            }
        }else printf("-1\n");
        
    }
    return 0;
}
