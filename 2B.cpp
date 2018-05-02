#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M,rest[101][101],dp[101][101],result=987654321;
        cin>>N>>M;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>rest[i][j];
                dp[i][j]=987654321;
            }
        }
        for(int i=0;i<N;i++)dp[i][0]=rest[i][0];
        for(int i=1;i<M;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    if(j==k)continue;
                    dp[j][i]=min(dp[j][i],dp[k][i-1]+rest[j][i]);
                }
            }
        }
        for(int i=0;i<N;i++)result=min(result,dp[i][M-1]);
        printf("%d\n",result);
    }
    return 0;
}
