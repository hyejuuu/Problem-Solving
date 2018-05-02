#include <iostream>
#include <string>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        string A,B;
        bool ch=0;
        cin>>A>>B;
        int Asize = (int)A.size();
        int Bsize = (int)B.size();
        for(int i=0;i< Asize;i++){
            for(int j=0;j < Bsize;j++){
                if(A[i]==B[j])break;
                if(j==Bsize-1)ch=1;
            }
        }
        if(!ch){
            for(int i=0;i<Bsize;i++){
                for(int j=0;j<Asize;j++){
                    if(B[i]==A[j])break;
                    if(j==Asize-1)ch=1;
                }
            }
        }
        if(ch)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
