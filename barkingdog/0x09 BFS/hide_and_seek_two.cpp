//
//  hide_and_seek_two.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

int N, K, totalTime, cnt;
bool visited[MAX];

void bfs(){
    queue<pair<int,int>> q;
    q.push({N,0});
    visited[N]=true;
    
    while(!q.empty()){
        int cur = q.front().first;
        int curTime = q.front().second;
        q.pop();
        
        visited[cur]=true;
        
        if(cnt==0){
            if(cur==K){
                totalTime=curTime;
                cnt++;
            }
        }
        else{
            if(cur==K && curTime==totalTime){
                cnt++;
            }
        }
        
        if(cur*2<MAX && !visited[cur*2]){
            q.push({cur*2,curTime+1});
        }
        if(cur+1<MAX && !visited[cur+1]){
            q.push({cur+1,curTime+1});
        }
        if(cur-1>-1 && !visited[cur-1]){
            q.push({cur-1,curTime+1});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>K;
    
    bfs();
    
    cout<<totalTime<<"\n"<<cnt;
}
