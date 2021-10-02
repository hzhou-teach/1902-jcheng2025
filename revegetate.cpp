/*
Name: Jonathan C
Time: 35 min
Testcases: ********** 10/10 
Difficulty: 7
Explination: The problem itself wasn't that hard but the description was really confusing and took me a while to understand the question.
*/
#include <bits/stdc++.h>
	
using namespace std;

int nextLexico(vector<int> vec, int key[]) {
	int next = 1;

	bool flag = false;
	//2 iterations, each trying to find if 1, 2, 3 exist respectively
	for(int it = 1; it <= 3; it++) {
		for(auto& i : vec) {
			if(key[i] == it) { //if it does, the next lexico number will increase by 1
				flag = true;
				next = it+1;
				break;
			}
		}

		if(flag) {
			flag = false;
			continue;
		}

		//if not, the current number is the next lecico number
		break;
	}

	return next;
}


int main() {

	ifstream fin("revegetate.in");
	ofstream fout("revegetate.out");

	int N, M;
	fin >> M >> N;

	vector<vector<int>> map(M+1);
	

	for(int i = 0; i < N; i++) {
				
		int a, b;
		fin >> a >> b; //the type of a and b must not be the same

		//store it in a map containing with the index of the map representing the pasture number and the values representing the ones that it cannot match
		if(find(map[a].begin(), map[a].end(), b) == map[a].end()) { 
			map[a].push_back(b);
		}
	       	if (find(map[b].begin(), map[b].end(), a) == map[b].end()) {
			map[b].push_back(a);
		}


	}

	//since we must construct the smallest, we find the lexicographically smallest integer for each value (the smallest integer that does not match the other values)
	int A[M+1] = {0};
	for(int i = 1; i < M+1; i++) {
		A[i] = nextLexico(map[i], A);
	}

	//print the constructed value
	for(int i = 1; i < M+1; i++) {
		fout << A[i];
	}
	fout << "\n";

	return 0;
}
