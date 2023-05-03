#include<iostream>
#include<vector>

using namespace std;

int main() {


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

	Edge test;

	test.read();

	cout << test.v1 << " " << test.v2;

	return 0;
}