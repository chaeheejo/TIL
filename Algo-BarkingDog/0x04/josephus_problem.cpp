//
//  josephus_problem.cpp
//  algorithm
//
//  Created by chaehee on 2023/08/15.
//

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin>>N>>K;
    
    list<int> L;
    for(int i=0;i<N;i++){
        L.push_back(i+1);
    }
    
    vector<int> answer;
    
    auto it = L.begin();
    for(int i=0;i<N;i++){
        for(int k=0;k<K-1;k++){
            if(it==L.end()) it = L.begin();
            it++;
            if(it==L.end()) it = L.begin();
        }
        answer.push_back(*it);
        it = L.erase(it);
    }
    
    cout<<"<";
    for(int i=0;i<answer.size();i++){
        if(i!=answer.size()-1){
            cout<<answer[i]<<", ";
        }
        else{
            cout<<answer[i]<<">";
        }
    }
    
    return 0;
}
