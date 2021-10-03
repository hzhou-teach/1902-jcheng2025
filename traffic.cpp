/*
Name: Jonathan C
Time: 30 min
USACO Testcases: Unifinished Code
Difficulty: 7
Reflection: Code is not yet finished but I could defenently find a result in another 4-5 minutes
*/

#include <bits/stdc++.h>

using namespace std;

int feasibleLow = 0;
int feasibleHigh = 0;

//why cant you return arrays in cpp?
void feasibleInterval(int a1, int a2) {
	feasibleLow = max(a1, feasibleLow);
	feasibleHigh = min(a2, feasibleHigh);
}

int main() {

	ifstream fin("traffic.in");
	ofstream fout("traffic.out");

	int N;
	fin >> N;

	vector<vector<int>> actions(N); 
	
	for(int i = 0; i < N; i++) {
		
		string a;
		int b, c;
		fin >> a >> b >> c;

		if(a == "on") {
			actions[i].push_back(0);
		} else if (a == "none") {
			actions[i].push_back(1);
		} else {
			actions[i].push_back(2);
		}

		actions[i].push_back(b);
		actions[i].push_back(c);
	}

	//calculate min by finding the nearest none ramp segment
	int ptr = 0;
	for(int i = 0; i < N; i++) {
		if(actions[i][0] == 1) {
			ptr = i;

			feasibleLow = actions[i][1];
			feasibleHigh = actions[i][2];

			while(i < N && actions[i][0] == 1) {
				feasibleInterval(actions[i][1], actions[i][2]);
				i++;
			}

			break;
		}
	}


	//start from that iteration and iterate backwards perform necessary operations. the answer is the first index
	for(int i = ptr-1; i >= 0; i--) {
		if(actions[i][0] == 0) {
			feasibleLow -= actions[i][2];
			feasibleHigh -= actions[i][1];
		} else if (actions[i][0] == 1) {
			feasibleInterval(actions[i][1], actions[i][2]);
		} else if (actions[i][0] == 2) {
			feasibleLow += actions[i][2];
			feasibleHigh += actions[i][1];
		}
	}

	//print the answer
	fout << max(feasibleLow, 0) << " " << feasibleHigh << "\n";
	
	//reset the value of feasibleLow and feasibleHigh by scanning for the last occurance of none ramps
	
	for(int i = N-1; i>=0; i--) {
		if(actions[i][0] == 1) {
			ptr = i;

			feasibleLow = actions[i][1];
			feasibleHigh = actions[i][2];

			while(i >= 0 && actions[i][0] == 1) {
				feasibleInterval(actions[i][1], actions[i][2]);
				i--;
			}

			break;
		}
	}

	//start from that iteration+1 and iterate forwards and perform necessary operations along the way
	for(int i = ptr+1; i < N; i++) {
		if(actions[i][0] == 0) {
			feasibleLow += actions[i][2];
			feasibleHigh += actions[i][1];
		} else if (actions[i][0] == 1) {
			feasibleInterval(actions[i][1], actions[i][2]);
		} else if (actions[i][0] == 2) {
			feasibleLow -= actions[i][2];
			feasibleHigh -= actions[i][1];
		}
	}

	fout << max(feasibleLow, 0) << " " << feasibleHigh << "\n";
	return 0;

}


	



