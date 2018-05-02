#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int len,ch=0;
        string str1,str2;
        cin>>str1;
        len=(int)str1.size();
        for(int i=len-1;i>=0;i--)str2.push_back(str1[i]);
        str1=to_string(atoi(str1.c_str())+atoi(str2.c_str()));
        len=(int)str1.size();
        for(int i=0;i<len/2;i++){
            if(str1[i]!=str1[len-i-1]){
                ch=1;
                break;
            }
        }
        if(!ch)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

