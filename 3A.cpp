#include <iostream>
using namespace std;

int N,arr[257][257]={0},dp[257][257]={0};
pair<int,int> cnt;

void func(int a,int b,int sz){
    if((dp[a][b]-dp[a-sz][b]-dp[a][b-sz]+dp[a-sz][b-sz])==0){
        cnt.first++;
        return;
    }else if((dp[a][b]-dp[a-sz][b]-dp[a][b-sz]+dp[a-sz][b-sz])==sz*sz){
        cnt.second++;
        return;
    }
    sz /= 2;
    func(a-sz,b,sz);
    func(a,b-sz,sz);
    func(a-sz,b-sz,sz);
    func(a,b,sz);
}

int main(){
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cnt={0,0};
        cin>>N;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                cin>>arr[i][j];
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1] +arr[i][j];
            }
        }
        func(N,N,N);
        cout<<cnt.first<<" "<<cnt.second<<"\n";
    }
    return 0;
}
