//
//  party.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001

struct Node{
    int to,cost;
    
    bool operator < (const Node right) const{
        if(cost<right.cost) return false;
        if(cost>right.cost) return true;
        return false;
    }
};

int N, M, X;
int dist[MAX];
int totalDist[MAX];
vector<Node> graph[MAX];

void dijkstra(int start){
    for(int i=0;i<N;i++){
        dist[i]=2e9;
    }
    
    priority_queue<Node> pq;
    pq.push({start,0});
    dist[start]=0;
    
    while (!pq.empty()) {
        Node curNode = pq.top();
        pq.pop();
        
        if(dist[curNode.to]<curNode.cost){
            continue;
        }
        
        for(int i=0;i<graph[curNode.to].size();i++){
            Node nextNode = graph[curNode.to][i];
            
            if(dist[nextNode.to]<=dist[curNode.to]+nextNode.cost){
                continue;
            }
            
            dist[nextNode.to]=dist[curNode.to]+nextNode.cost;
            pq.push({nextNode.to, dist[nextNode.to]});
        }
    }
}

int main(){
    
    cin>>N>>M>>X;
    
    X-=1;
    
    for(int i=0;i<M;i++){
        int from, to, cost;
        cin>>from>>to>>cost;
        
        graph[from-1].push_back({to-1,cost});
    }
    
    dijkstra(X);
    
    for(int i=0;i<N;i++){
        if(X==i) continue;
        totalDist[i]=dist[i];
    }
    
    for(int i=0;i<N;i++){
        if(X==i) continue;
        dijkstra(i);
        totalDist[i]+=dist[X];
    }
    
    int answer=0;
    for(int i=0;i<N;i++){
        if(answer<totalDist[i]){
            answer=totalDist[i];
        }
    }
    
    cout<<answer;
    
    return 0;
}
