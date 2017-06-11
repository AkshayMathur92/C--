# include <iostream>
# include <stdexcept>
# include <vector>
# include <queue>
# include <stack>

class Graph {
	std::vector<std::vector<int> > v;
	int size;
public: 
	Graph(int vertices):v(vertices, std::vector<int> (vertices)), size(vertices){}
	void add_edge(int v1, int v2){
		if(v1 >= size || v2 >= size ){
			throw std::invalid_argument("indexes must be less than" + std::to_string(size));
		}
		v[v1][v2] = 1;
		v[v2][v1] = 1;
	}
	void add_edge(int v1, int v2, int weight){
		if(v1 >= size || v2 >= size ){
			throw std::invalid_argument("indexes must be less than" + std::to_string(size));
		}
		v[v1][v2] = weight;
		v[v2][v1] = weight;
	}
	void BFS(){
		std::queue<int> q;
		std::vector<bool> visited(size);
		q.push(0);
		visited[0] = true;
		while(!q.empty()){
			auto temp = q.front();
			q.pop();
			std::cout << temp << " ";
			for(int i = 0; i < size; i ++){
				if(!visited[i] && v[temp][i] != 0){
					q.push(i);
					visited[i] = true;
				}
			}
		}
		std::cout << std::endl;
	}
	void DFS(){
		std::vector<bool> v(size);
		DFS(0, v);
		std::cout << std::endl;
	}
	void DFS(int index, std::vector<bool> &visited){
		visited[index] = true;
		std::cout << index << " ";
		for(int i = 0; i < size; i++){
			if(!visited[i] && v[index][i] != 0){
				DFS(i , visited);
			}
		}
	}
};
int main(){
	Graph g(6);
	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(1,3);
	g.add_edge(3,4);
	g.add_edge(4,5);
	g.add_edge(4,1);
	g.BFS();
	g.DFS();
}