#include<iostream>
#include<vector>
#include"Graph.h"

using namespace std;

//function to determine whether a path is promising
bool promising(int i, vector<int>& colors, Graph& const g) {
	int j = 0;

	//runs through all visited vertices and checks for adjacency and color
	while (j < i) {
		if ((g.isAdjacent(i, j)) && (colors.at(i) == colors.at(j))) {
			//if vertices are adjacent and the same color
			return false;
		}
		j++;
	}
	return true;
}

//global flag to end recursion in all function instances when a solution is found
bool found = false;

//Main function for the backtracking algorithm
void graphColors(int i, int m, Graph& g, vector<int>& vColor) {
	int color;

	//global flag case
	if (found) {
		return;
	}

	
	if (promising(i, vColor, g)) {	//checks if the current path should be continued
		if (i == (g.getNumVertices() - 1)) { //checks if a solution has been found
			found = true; //triggers global flag
			return;
		}
		else {
			for (color = 1; color <= m && !found; color++) { //Tries every color for the next vertice
				vColor.at(i+1) = color;
				graphColors(i + 1, m, g, vColor);
			}
		}
	}
}

//Basically a wrapper function to manage the algorithm.
void mColors(int i, int m, Graph& const g) {
	vector<int> vColor(g.getNumVertices()); //initialize vColor 
	
	graphColors(i, m, g, vColor); //call main algorithm.

	if (found) { // printing for solution found
		for (int x = 0; x < vColor.size(); x++) {
			cout << x << " : " << vColor.at(x) << endl;
		}
	}
	else { // printing for no solution found
		cout << "No color assignment possible." << endl;
	}
	
}

int main() {

	Graph g;
	int colors;

	cin >> colors;

	g.read(); //create adjacency matrix from user input

	//g.printAdj();

	/*for (auto i : optColors) {
		cout << i << endl;
	}
	cout << g.getNumVertices();*/

	mColors(-1, colors, g);
	

	return 0;
}