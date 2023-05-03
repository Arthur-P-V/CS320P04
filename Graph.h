#include<iostream>
#include<vector>

using namespace std;


class Graph {
private:
	size_t numVertices;
	vector<vector<int>> adjMatrix;

	struct Edge {
		int v1;
		int v2;
		Edge(int vi = -2, int vj = -2) { v1 = vi; v2 = vj; }

		// reads in (0 1) as an edge with v1 as 0 and v2 as 1 for easier manipulation in graph read function
		void read() {
			char garbage;
			cin >> garbage >> this->v1 >> this->v2 >> garbage;
		}
	};

public:
	
	Graph() :numVertices(0) {};
	~Graph() {}; //use default destructor
	int getNumVertices() { return numVertices; };

	//read in the adjacency matrix from user input
	void read() {
		Edge temp;
		cin >> numVertices;

		adjMatrix.resize(numVertices, vector<int>(numVertices));

		temp.read();
		while ((temp.v1 != -1) && (temp.v2 != -1)) {
			adjMatrix[temp.v1][temp.v2] = 1;
			temp.read();
		}
	}

	void printAdj() {
		for (int i = 0; i < numVertices; ++i) {
			for (int j = 0; j < numVertices; ++j) {
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	//determine whether two vertices are adjacent
	bool isAdjacent(int v1, int v2) {
		return (adjMatrix[v1][v2] == 1) ? true : false;
	};

};