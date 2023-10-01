//
//  find_minimum_cost.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001
#define INF (~0U>>2)

struct Node{
    int to,cost;
    bool operator<(const Node right)const{
        if(cost<right.cost) return false;
        if(cost>right.cost) return true;
        return true;
    }
};

int N, M, S, D;
vector<Node> graph[MAX];
int dist[MAX];

void dijkstra(int start){
    for(int i=0;i<N;i++){
        dist[i]=INF;
    }
    
    priority_queue<Node> pq;
    pq.push({start,0});
    dist[start]=0;
    
    while(!pq.empty()){
        Node curNode = pq.top();
        pq.pop();
        
        if(dist[curNode.to]<curNode.cost)
            continue;
        
        for(int i=0;i<graph[curNode.to].size();i++){
            Node nextNode = graph[curNode.to][i];
            
            if(dist[nextNode.to]<=dist[curNode.to]+nextNode.cost)
                continue;
            
            dist[nextNode.to]=dist[curNode.to]+nextNode.cost;
            pq.push({nextNode.to, dist[nextNode.to]});
        }
    }
}

int main(){
    
    cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        
        graph[from-1].push_back({to-1,cost});
    }
    
    cin>>S>>D;
    
    dijkstra(S-1);
    
    cout<<dist[D-1];
    
    return 0;
}
