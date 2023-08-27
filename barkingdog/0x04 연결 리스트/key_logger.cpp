//
//  key_logger.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/15.
//

#include <iostream>
#include <list>
using namespace std;

int main(){
    
    int N;
    cin>>N;
    
    for(int n=0;n<N;n++){
        string cmd;
        cin>>cmd;
        
        list<char> L;
        list<char>::iterator it = L.end();
        for(int i=0;i<cmd.size();i++){
            if(cmd[i]=='<'){
                if(it!=L.begin()){
                    it--;
                }
            }
            else if(cmd[i]=='>'){
                if(it!=L.end()){
                    it++;
                }
            }
            else if(cmd[i]=='-'){
                if(it!=L.begin()){
                    it--;
                    it = L.erase(it);
                }
            }
            else{
                L.insert(it,cmd[i]);
            }
        }
        
        for(auto item: L){
            cout<<item;
        }
        cout<<'\n';
    }
    
    return 0;
}
