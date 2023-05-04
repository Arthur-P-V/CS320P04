#include<iostream>
#include<vector>
#include"Graph.h"

using namespace std;

//function to determine whether a 
bool promising(int i, vector<int>& colors, Graph& const g) {
	int j = 0;
	bool flag = true;

	while ((j < i) && flag) {
		if ((g.isAdjacent(i, j)) && (colors.at(i) == colors.at(j))) {
			flag = false;
		}
		j++;
	}
	return flag;
}

bool found = false;

void graphColors(int i, int m, Graph& g, vector<int>& vColor) {
	int color;

	if (found) {
		return;
	}

	if (promising(i, vColor, g)) {
		if (i == (g.getNumVertices() - 1)) {
			found = true;
			return;
		}
		else {
			for (color = 1; color <= m; color++) {
				vColor.at(i+1) = color;
				graphColors(i + 1, m, g, vColor);
			}
		}
	}
}

void mColors(int i, int m, Graph& const g) {
	vector<int> vColor(g.getNumVertices(), -2);
	
	graphColors(i, m, g, vColor);

	for (int x = 0; x < vColor.size(); x++) {
		cout << x << " : " << vColor.at(x) << endl;
	}
}

int main() {

	Graph g;
	int colors;

	cin >> colors;

	g.read();
	
	vector<int> optColors(g.getNumVertices(), -2);

	/*for (auto i : optColors) {
		cout << i << endl;
	}
	cout << g.getNumVertices();*/

	mColors(-1, colors, g);
	

	return 0;
}