#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int alpa[26]={0};

string func(){
    int len=(int)str.length();
    
    for(int i=0;i<len;i++) alpa[str[i]-'A']=1;
    
    for(int i=len-1;i>0;i--){
        if(str[i]>str[i-1]){
            for(int j=str[i-1]-'A';j<26;j++){
                if(alpa[j+1]==1){
                    for(int k=i;k<len;k++){
                        if(str[k]==j+1+'A'){
                            swap(str[i-1],str[k]);
                            sort(&str[i],&str[len]);
                            return str;
                        }
                    }
                }
            }
        }
    }
    return str;
}

int main(){
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cin>>str;
        cout<<func()<<"\n";
    }
    return 0;
}
