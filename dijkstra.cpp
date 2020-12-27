
#include<iostream>
#include <limits.h> 
using namespace std;
//maximum size of node i have assumed      
#define A 6
int graph[A][A]={0};
//function for inserting node in a graph
void insertnode(int s, int d, int w){
graph[s][d]=w;
}
//this function will find minimu~m distance and return the node
int mindist(bool v[],int dist[]){
//assigning maximum possible integer value
int min=INT_MAX;
//in minindex we will store a index no.
int minindex;
for(int I=0;I<A;I++){
if(v[I]==false&&dist[I]<=min){
min=dist[I];
minindex=I;
}
}
return minindex;
}  
//this function is basically dijkstra algorithm here as an argument the node no. will be passed 
void Dijkstra(int source){
//this array will contain minimum distance from source node to node i
int dist[A];
//this array will keep a track of which node is visited and which not
//false for not visited
//true for visited
bool visited[A];
for(int q=0;q<A;q++){
	//in starting in visited array we will assign a false
	//and also in starting in dist array we will assign a maximum possible integer value
	visited[q]=false;
	dist[q]=INT_MAX;
}
//source to source node distance is 0
dist[source]=0;
for(int count=0;count<A-1;count++){
//mindist function is called for finding minimum distance
int u=mindist(visited,dist);
//marking u node as visited
 visited[u]=true;
for(int V=0;V<A;V++){
 
 if(!visited[V]&&graph[u][V]&&dist[u]!=INT_MAX&&dist[u]+graph[u][V]<dist[V]){
 	//updating distance
 dist[V]=dist[u]+graph[u][V];
}

}
}
//for printing source array
cout<<"source node:"<<source<<endl;
for(int I=1;I<A;I++){
cout<<I<<" "<<dist[I]<<endl;
}
}
int main(){
//for creating graph
insertnode(0,1,50);
insertnode(0,2,45);
insertnode(0,3,10);
insertnode(3,0,10);
insertnode(3,4,15);
insertnode(5,4,3);
insertnode(2,4,30);
insertnode(4,2,35);
insertnode(4,1,20);
insertnode(1,2,10);
insertnode(1,3,15);
insertnode(4,5,12);
int source;
cout<<"enter source node."<<endl;
cin>>source;
Dijkstra(source);


return 0;}

