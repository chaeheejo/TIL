//
//  editor.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/15.
//

#include <iostream>
#include <list>
using namespace std;

list<char> L;

int main(){
    
    string init;
    cin>>init;
    
    for(int i=0;i<init.size();i++){
        L.push_back(init[i]);
    }
    
    list<char>::iterator it = L.end();
    
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++){
        char cmd;
        cin>>cmd;
        
        if(cmd=='L'){
            if(it!=L.begin()){
                it--;
            }
        }
        else if(cmd=='D'){
            if(it!=L.end()){
                it++;
            }
        }
        else if(cmd=='B'){
            if(it!=L.begin()){
                it--;
                it = L.erase(it);
            }
        }
        else{
            char addItem;
            cin>>addItem;
            L.insert(it, addItem);
        }
    }
    
    for(auto item: L){
        cout<<item;
    }
    
    return 0;
}
