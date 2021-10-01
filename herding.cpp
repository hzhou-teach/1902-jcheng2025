/*
Name: Jonathan C
Time: 6 min
USACO Test Cases: ********** 10/10
Difficulty: 4/10
Reflection: A logic problem that was somewhat difficult to understand. Minimum was really easy and maximum was really hard to prove.
*/

#include <fstream>
#include <iostream>

using namespace std;

int main() {

	ifstream fin("herding.in");
	ofstream fout("herding.out");

	int A[3];
	fin >> A[0] >> A[1] >> A[2];

	//find min
	if(A[2]-A[1] == 2 || A[1]-A[0] == 2) { //if 2 consecutive numbers differ by 2, then we can change the third number to be inbetween the first two. 1 move
		fout << 1 << "\n";
	} else if (A[2]-A[1] == 1 && A[1]-A[0] == 1) { //all 3 numbers are already in order. 0 Moves
		fout << 0 << "\n";
	} else { //otherwise, the answer will always be 2. 
		fout << 2 << "\n"; 
	}



	//find the biggest range inbetween numbers. The other number will be a max/min and we swap the other two numbers repeadatly by 1 until we obtain a strictly increasing sequence.
	//the answer will always be the largest range -1
	fout << max(A[2]-A[1], A[1]-A[0])-1; 

	return 0;
}
