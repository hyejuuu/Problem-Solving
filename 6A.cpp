#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M,A[1001],B[1001],dp[1001][1001]={0},mn=INF;
        cin>>N>>M;
        for(int i=1;i<=M;i++){
            cin>>A[i];
            B[i]=A[i];
        }
        A[0]=0;B[0]=N;
        for(int i=0;i<=M;i++){
            for(int j=0;j<=M;j++){
                if(i==j)continue;
                if(i>j){
                    if(j==i-1&&i!=1){
                        dp[i][j]=INF;
                        for(int k=i;k>1;k--){
                            dp[i][j]=min(dp[i][j],dp[i-k][j]+abs(A[i]-A[i-k]));
                        }
                    }
                    else dp[i][j]=dp[i-1][j]+abs(A[i]-A[i-1]);
                    if(i==M)mn=min(mn,dp[i][j]);
                }
                else{
                    if(i==j-1&&j!=1){
                        dp[i][j]=INF;
                        for(int k=j;k>1;k--){
                            dp[i][j]=min(dp[i][j],dp[i][j-k]+abs(B[j]-B[j-k]));
                        }
                    }
                    else dp[i][j]=dp[i][j-1]+abs(B[j]-B[j-1]);
                    if(j==M)mn=min(mn,dp[i][j]);
                }
            }
        }
        printf("%d\n",mn);
    }
    return 0;
}
