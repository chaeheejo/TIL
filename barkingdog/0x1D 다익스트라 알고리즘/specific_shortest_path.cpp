//
//  specific_shortest_path.cpp
//  algorithm
//
//  Created by chaehee on 2023/10/01.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 801
#define INF 2e9

struct Node{
    int to,cost;
    
    bool operator<(const Node right)const{
        if(cost<right.cost) return false;
        if(cost>right.cost) return true;
        return true;
    }
};

int N, E, V1, V2;
vector<Node> graph[MAX];
int dist[MAX];

void dijkstra(int start){
    for(int i=0;i<N;i++){
        dist[i]=INF;
    }
    
    priority_queue<Node> pq;
    pq.push({start,0});
    dist[start]=0;
    
    while (!pq.empty()) {
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

int getAnswerFirst(){
    
    dijkstra(0);
    if(dist[V1]==INF){
        return -1;
    }
    int rtn = dist[V1]; //0~V1
    
    dijkstra(V1);
    if(dist[V2]==INF){
        return -1;
    }
    rtn+=dist[V2]; //V1~V2
    
    dijkstra(V2);
    if(dist[N-1]==INF){
        return -1;
    }
    rtn+=dist[N-1]; //V2~N-1
    
    return rtn;
}

int getAnswerSecond(){
    
    dijkstra(0);
    if(dist[V2]==INF){
        return -1;
    }
    int rtn = dist[V2]; //0~V2
    
    dijkstra(V2);
    if(dist[V1]==INF){
        return -1;
    }
    rtn+=dist[V1]; //V2~V1
    
    dijkstra(V1);
    if(dist[N-1]==INF){
        return -1;
    }
    rtn+=dist[N-1]; //V1~N-1
    
    return rtn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>E;
    
    for(int i=0;i<E;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        
        graph[from-1].push_back({to-1,cost});
        graph[to-1].push_back({from-1,cost});
    }
    
    cin>>V1>>V2;
    
    V1-=1;
    V2-=1;
    
    //case1. 1 > ... > V1 > ... > V2 > ... > N
    //case2. 1 > ... > V2 > ... > V1 > ... > N
    
    int case1 = getAnswerFirst();
    int case2 = getAnswerSecond();
    
    if(case1!=-1 && case2!=-1){
        if(case1>case2){
            cout<<case2;
        }
        else{
            cout<<case1;
        }
    }
    else if(case1==-1){
        cout<<case2;
    }
    else if(case2==-1){
        cout<<case1;
    }
    else{
        cout<<-1;
    }
    
    return 0;
}
