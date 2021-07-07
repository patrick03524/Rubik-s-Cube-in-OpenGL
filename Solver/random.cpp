#include<iostream>
#include<string>
#include<vector> 
#include <cstdlib> 
#include <ctime> 
#include "random.h"
using namespace std;

int randomNum() {
	int a = rand() % 100 + 1;
	return a;
}
std::vector<std::string> scramble(int N_M) {
	char setArray[6] = { 'U', 'F', 'B', 'D', 'R', 'L' };
	srand(time(0));
	int i = 0;
	char completedMove = 'Q';
	int totalNum;
	int inputLength = N_M;
	std::vector<std::string> moves(inputLength);
	int index = 0;
	while (i < inputLength) {
		bool doTwo = false;
		bool addOne = false;
		bool ignore = false;
		int r = randomNum();
		int initFirst = (r % 10);
		int initNon = ((int)(r / 10));
		if ((initNon) > 5) {
			addOne = true;
		}
		if ((((initNon) * 3) % 10) > 3) {
			doTwo = true;
		}
		if (initFirst > 5) {
			initFirst = initFirst / 2;
		}
		char turn;
		turn = setArray[initFirst];
		r /= 10;
		if (turn != completedMove) {
			if (addOne == true && ignore == false && turn != NULL) {
				if (doTwo == true) {
					//cout << turn << "2";
					moves[index].push_back(turn);
					moves[index].push_back('2'); ++index; ++i;
				}
				else {
					//cout << turn << "'";
					moves[index].push_back(turn);
					moves[index].push_back('\''); ++index; ++i;
				}
			}
			else if (addOne != true && ignore == false && turn != NULL) {
				if (doTwo == true) {
					//cout << turn << "2";
					moves[index].push_back(turn);
					moves[index].push_back('2'); ++index; ++i;
				}
				else {
					//cout << turn;
					moves[index].push_back(turn); ++index; ++i;
				}

			}
			if (ignore == false) {
				//cout << "x";
			}
		}

		completedMove = turn;


	}
	//cout << "\n";
	return moves;
}

void cara0(char* R) {
	for (int i = 0; i < 9; ++i) {
		R[i] = 'U';
	}
}
void cara1(char* R) {
	for (int i = 0; i < 9; ++i) {
		R[i] = 'R';
	}
}
void cara2(char* R) {
	for (int i = 0; i < 9; ++i) {
		R[i] = 'F';
	}
}
void cara3(char* R) {
	for (int i = 0; i < 9; ++i) {
		R[i] = 'D';
	}
}
void cara4(char* R) {
	for (int i = 0; i < 9; ++i) {
		R[i] = 'L';
	}
}
void cara5(char* R) {
	for (int i = 0; i < 9; ++i) {
		R[i] = 'B';
	}
}

void print(char R[6][3][3]) {
	for (int f = 0; f < 6; ++f) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << R[f][i][j];
			}
		}
	}
}
void giroU(char R[6][3][3], int c) {//Testing 100%
	char Rtemp[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			Rtemp[i][j] = R[0][i][j];
		}
	}
	string tempedges;
	tempedges.push_back(R[1][0][2]);
	tempedges.push_back(R[1][0][1]);
	tempedges.push_back(R[1][0][0]);
	tempedges.push_back(R[2][0][2]);
	tempedges.push_back(R[2][0][1]);
	tempedges.push_back(R[2][0][0]);
	tempedges.push_back(R[4][0][2]);
	tempedges.push_back(R[4][0][1]);
	tempedges.push_back(R[4][0][0]);
	tempedges.push_back(R[5][0][2]);
	tempedges.push_back(R[5][0][1]);
	tempedges.push_back(R[5][0][0]);
	tempedges = tempedges + tempedges;
	if (c) {//clockwise
		R[0][0][0] = Rtemp[2][0];
		R[0][0][1] = Rtemp[1][0];
		R[0][0][2] = Rtemp[0][0];
		R[0][1][0] = Rtemp[2][1];
		R[0][1][1] = Rtemp[1][1];
		R[0][1][2] = Rtemp[0][1];
		R[0][2][0] = Rtemp[2][2];
		R[0][2][1] = Rtemp[1][2];
		R[0][2][2] = Rtemp[0][2];
		R[1][0][2] = tempedges[9];
		R[1][0][1] = tempedges[10];
		R[1][0][0] = tempedges[11];
		R[2][0][2] = tempedges[0];
		R[2][0][1] = tempedges[1];
		R[2][0][0] = tempedges[2];
		R[4][0][2] = tempedges[3];
		R[4][0][1] = tempedges[4];
		R[4][0][0] = tempedges[5];
		R[5][0][2] = tempedges[6];
		R[5][0][1] = tempedges[7];
		R[5][0][0] = tempedges[8];
	}
	else {//counter
		R[0][0][0] = Rtemp[0][2];
		R[0][0][1] = Rtemp[1][2];
		R[0][0][2] = Rtemp[2][2];
		R[0][1][0] = Rtemp[0][1];
		R[0][1][1] = Rtemp[1][1];
		R[0][1][2] = Rtemp[2][1];
		R[0][2][0] = Rtemp[0][0];
		R[0][2][1] = Rtemp[1][0];
		R[0][2][2] = Rtemp[2][0];
		R[1][0][2] = tempedges[3];
		R[1][0][1] = tempedges[4];
		R[1][0][0] = tempedges[5];
		R[2][0][2] = tempedges[6];
		R[2][0][1] = tempedges[7];
		R[2][0][0] = tempedges[8];
		R[4][0][2] = tempedges[9];
		R[4][0][1] = tempedges[10];
		R[4][0][0] = tempedges[11];
		R[5][0][2] = tempedges[12];
		R[5][0][1] = tempedges[13];
		R[5][0][0] = tempedges[14];
	}
}
void giroR(char R[6][3][3], int c) {//Testing 100%
	char Rtemp[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			Rtemp[i][j] = R[1][i][j];
		}
	}
	string tempedges;
	tempedges.push_back(R[2][2][2]);//
	tempedges.push_back(R[2][1][2]);//
	tempedges.push_back(R[2][0][2]);//
	tempedges.push_back(R[0][2][2]);//
	tempedges.push_back(R[0][1][2]);//
	tempedges.push_back(R[0][0][2]);//
	tempedges.push_back(R[5][0][0]);//
	tempedges.push_back(R[5][1][0]);//
	tempedges.push_back(R[5][2][0]);//
	tempedges.push_back(R[3][0][0]);//
	tempedges.push_back(R[3][1][0]);//
	tempedges.push_back(R[3][2][0]);//
	tempedges = tempedges + tempedges;
	if (c) {//clockwise
		R[1][0][0] = Rtemp[2][0];
		R[1][0][1] = Rtemp[1][0];
		R[1][0][2] = Rtemp[0][0];
		R[1][1][0] = Rtemp[2][1];
		R[1][1][1] = Rtemp[1][1];
		R[1][1][2] = Rtemp[0][1];
		R[1][2][0] = Rtemp[2][2];
		R[1][2][1] = Rtemp[1][2];
		R[1][2][2] = Rtemp[0][2];
		R[2][2][2] = tempedges[9];//
		R[2][1][2] = tempedges[10];//
		R[2][0][2] = tempedges[11];//
		R[0][2][2] = tempedges[0];//
		R[0][1][2] = tempedges[1];//
		R[0][0][2] = tempedges[2];//
		R[5][0][0] = tempedges[3];//
		R[5][1][0] = tempedges[4];//
		R[5][2][0] = tempedges[5];//
		R[3][0][0] = tempedges[6];//
		R[3][1][0] = tempedges[7];//
		R[3][2][0] = tempedges[8];//
	}
	else {//counter
		R[1][0][0] = Rtemp[0][2];
		R[1][0][1] = Rtemp[1][2];
		R[1][0][2] = Rtemp[2][2];
		R[1][1][0] = Rtemp[0][1];
		R[1][1][1] = Rtemp[1][1];
		R[1][1][2] = Rtemp[2][1];
		R[1][2][0] = Rtemp[0][0];
		R[1][2][1] = Rtemp[1][0];
		R[1][2][2] = Rtemp[2][0];
		R[2][2][2] = tempedges[3];//
		R[2][1][2] = tempedges[4];//
		R[2][0][2] = tempedges[5];//
		R[0][2][2] = tempedges[6];//
		R[0][1][2] = tempedges[7];//
		R[0][0][2] = tempedges[8];//
		R[5][0][0] = tempedges[9];//
		R[5][1][0] = tempedges[10];//
		R[5][2][0] = tempedges[11];//
		R[3][0][0] = tempedges[12];//
		R[3][1][0] = tempedges[13];//
		R[3][2][0] = tempedges[14];//
	}
}
void giroF(char R[6][3][3], int c) {//Testing 100%
	char Rtemp[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			Rtemp[i][j] = R[2][i][j];
		}
	}
	string tempedges;
	tempedges.push_back(R[4][2][2]);//*
	tempedges.push_back(R[4][1][2]);//*
	tempedges.push_back(R[4][0][2]);//*
	tempedges.push_back(R[0][2][0]);//*
	tempedges.push_back(R[0][2][1]);//*
	tempedges.push_back(R[0][2][2]);//*
	tempedges.push_back(R[1][0][0]);//*
	tempedges.push_back(R[1][1][0]);//*
	tempedges.push_back(R[1][2][0]);//*
	tempedges.push_back(R[3][2][0]);//*
	tempedges.push_back(R[3][2][1]);//*
	tempedges.push_back(R[3][2][2]);//*
	tempedges = tempedges + tempedges;
	if (c) {//clockwise
		R[2][0][0] = Rtemp[2][0];
		R[2][0][1] = Rtemp[1][0];
		R[2][0][2] = Rtemp[0][0];
		R[2][1][0] = Rtemp[2][1];
		R[2][1][1] = Rtemp[1][1];
		R[2][1][2] = Rtemp[0][1];
		R[2][2][0] = Rtemp[2][2];
		R[2][2][1] = Rtemp[1][2];
		R[2][2][2] = Rtemp[0][2];
		R[4][2][2] = tempedges[9];//*
		R[4][1][2] = tempedges[10];//*
		R[4][0][2] = tempedges[11];//*
		R[0][2][0] = tempedges[0];//*
		R[0][2][1] = tempedges[1];//*
		R[0][2][2] = tempedges[2];//*
		R[1][0][0] = tempedges[3];//*
		R[1][1][0] = tempedges[4];//*
		R[1][2][0] = tempedges[5];//*
		R[3][2][0] = tempedges[6];//*
		R[3][2][1] = tempedges[7];//*
		R[3][2][2] = tempedges[8];//*
	}
	else {//counter
		R[2][0][0] = Rtemp[0][2];
		R[2][0][1] = Rtemp[1][2];
		R[2][0][2] = Rtemp[2][2];
		R[2][1][0] = Rtemp[0][1];
		R[2][1][1] = Rtemp[1][1];
		R[2][1][2] = Rtemp[2][1];
		R[2][2][0] = Rtemp[0][0];
		R[2][2][1] = Rtemp[1][0];
		R[2][2][2] = Rtemp[2][0];
		R[4][2][2] = tempedges[3];//*
		R[4][1][2] = tempedges[4];//*
		R[4][0][2] = tempedges[5];//*
		R[0][2][0] = tempedges[6];//*
		R[0][2][1] = tempedges[7];//*
		R[0][2][2] = tempedges[8];//*
		R[1][0][0] = tempedges[9];//*
		R[1][1][0] = tempedges[10];//*
		R[1][2][0] = tempedges[11];//*
		R[3][2][0] = tempedges[12];//*
		R[3][2][1] = tempedges[13];//*
		R[3][2][2] = tempedges[14];//*
	}
}
void giroD(char R[6][3][3], int c) {//Testing 100%
	char Rtemp[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			Rtemp[i][j] = R[3][i][j];
		}
	}
	string tempedges;
	tempedges.push_back(R[1][2][2]);
	tempedges.push_back(R[1][2][1]);
	tempedges.push_back(R[1][2][0]);
	tempedges.push_back(R[2][2][2]);
	tempedges.push_back(R[2][2][1]);
	tempedges.push_back(R[2][2][0]);
	tempedges.push_back(R[4][2][2]);
	tempedges.push_back(R[4][2][1]);
	tempedges.push_back(R[4][2][0]);
	tempedges.push_back(R[5][2][2]);
	tempedges.push_back(R[5][2][1]);
	tempedges.push_back(R[5][2][0]);
	tempedges = tempedges + tempedges;
	if (c) {//clockwise
		R[3][0][0] = Rtemp[2][0];
		R[3][0][1] = Rtemp[1][0];
		R[3][0][2] = Rtemp[0][0];
		R[3][1][0] = Rtemp[2][1];
		R[3][1][1] = Rtemp[1][1];
		R[3][1][2] = Rtemp[0][1];
		R[3][2][0] = Rtemp[2][2];
		R[3][2][1] = Rtemp[1][2];
		R[3][2][2] = Rtemp[0][2];
		R[1][2][2] = tempedges[3];
		R[1][2][1] = tempedges[4];
		R[1][2][0] = tempedges[5];
		R[2][2][2] = tempedges[6];
		R[2][2][1] = tempedges[7];
		R[2][2][0] = tempedges[8];
		R[4][2][2] = tempedges[9];
		R[4][2][1] = tempedges[10];
		R[4][2][0] = tempedges[11];
		R[5][2][2] = tempedges[12];
		R[5][2][1] = tempedges[13];
		R[5][2][0] = tempedges[14];
	}
	else {//counter
		R[3][0][0] = Rtemp[0][2];
		R[3][0][1] = Rtemp[1][2];
		R[3][0][2] = Rtemp[2][2];
		R[3][1][0] = Rtemp[0][1];
		R[3][1][1] = Rtemp[1][1];
		R[3][1][2] = Rtemp[2][1];
		R[3][2][0] = Rtemp[0][0];
		R[3][2][1] = Rtemp[1][0];
		R[3][2][2] = Rtemp[2][0];
		R[1][2][2] = tempedges[9];
		R[1][2][1] = tempedges[10];
		R[1][2][0] = tempedges[11];
		R[2][2][2] = tempedges[0];
		R[2][2][1] = tempedges[1];
		R[2][2][0] = tempedges[2];
		R[4][2][2] = tempedges[3];
		R[4][2][1] = tempedges[4];
		R[4][2][0] = tempedges[5];
		R[5][2][2] = tempedges[6];
		R[5][2][1] = tempedges[7];
		R[5][2][0] = tempedges[8];
	}
}
void giroL(char R[6][3][3], int c) {//Testing 100%
	char Rtemp[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			Rtemp[i][j] = R[4][i][j];
		}
	}
	string tempedges;
	tempedges.push_back(R[2][2][0]);//
	tempedges.push_back(R[2][1][0]);//
	tempedges.push_back(R[2][0][0]);//
	tempedges.push_back(R[0][2][0]);//
	tempedges.push_back(R[0][1][0]);//
	tempedges.push_back(R[0][0][0]);//
	tempedges.push_back(R[5][0][2]);//
	tempedges.push_back(R[5][1][2]);//
	tempedges.push_back(R[5][2][2]);//
	tempedges.push_back(R[3][0][2]);//
	tempedges.push_back(R[3][1][2]);//
	tempedges.push_back(R[3][2][2]);//
	tempedges = tempedges + tempedges;
	if (c) {//clockwise
		R[4][0][0] = Rtemp[2][0];
		R[4][0][1] = Rtemp[1][0];
		R[4][0][2] = Rtemp[0][0];
		R[4][1][0] = Rtemp[2][1];
		R[4][1][1] = Rtemp[1][1];
		R[4][1][2] = Rtemp[0][1];
		R[4][2][0] = Rtemp[2][2];
		R[4][2][1] = Rtemp[1][2];
		R[4][2][2] = Rtemp[0][2];
		R[2][2][0] = tempedges[3];//
		R[2][1][0] = tempedges[4];//
		R[2][0][0] = tempedges[5];//
		R[0][2][0] = tempedges[6];//
		R[0][1][0] = tempedges[7];//
		R[0][0][0] = tempedges[8];//
		R[5][0][2] = tempedges[9];//
		R[5][1][2] = tempedges[10];//
		R[5][2][2] = tempedges[11];//
		R[3][0][2] = tempedges[12];//
		R[3][1][2] = tempedges[13];//
		R[3][2][2] = tempedges[14];//
	}
	else {//counter
		R[4][0][0] = Rtemp[0][2];
		R[4][0][1] = Rtemp[1][2];
		R[4][0][2] = Rtemp[2][2];
		R[4][1][0] = Rtemp[0][1];
		R[4][1][1] = Rtemp[1][1];
		R[4][1][2] = Rtemp[2][1];
		R[4][2][0] = Rtemp[0][0];
		R[4][2][1] = Rtemp[1][0];
		R[4][2][2] = Rtemp[2][0];
		R[2][2][0] = tempedges[9];//
		R[2][1][0] = tempedges[10];//
		R[2][0][0] = tempedges[11];//
		R[0][2][0] = tempedges[0];//
		R[0][1][0] = tempedges[1];//
		R[0][0][0] = tempedges[2];//
		R[5][0][2] = tempedges[3];//
		R[5][1][2] = tempedges[4];//
		R[5][2][2] = tempedges[5];//
		R[3][0][2] = tempedges[6];//
		R[3][1][2] = tempedges[7];//
		R[3][2][2] = tempedges[8];//
	}
}
void giroB(char R[6][3][3], int c) {//Testing 1005
	char Rtemp[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			Rtemp[i][j] = R[5][i][j];
		}
	}
	string tempedges;
	tempedges.push_back(R[4][2][0]);//*
	tempedges.push_back(R[4][1][0]);//*
	tempedges.push_back(R[4][0][0]);//*
	tempedges.push_back(R[0][0][0]);//*
	tempedges.push_back(R[0][0][1]);//*
	tempedges.push_back(R[0][0][2]);//*
	tempedges.push_back(R[1][0][2]);//*
	tempedges.push_back(R[1][1][2]);//*
	tempedges.push_back(R[1][2][2]);//*
	tempedges.push_back(R[3][0][0]);//*
	tempedges.push_back(R[3][0][1]);//*
	tempedges.push_back(R[3][0][2]);//*
	tempedges = tempedges + tempedges;
	if (c) {//clockwise
		R[5][0][0] = Rtemp[2][0];
		R[5][0][1] = Rtemp[1][0];
		R[5][0][2] = Rtemp[0][0];
		R[5][1][0] = Rtemp[2][1];
		R[5][1][1] = Rtemp[1][1];
		R[5][1][2] = Rtemp[0][1];
		R[5][2][0] = Rtemp[2][2];
		R[5][2][1] = Rtemp[1][2];
		R[5][2][2] = Rtemp[0][2];
		R[4][2][0] = tempedges[3];//*
		R[4][1][0] = tempedges[4];//*
		R[4][0][0] = tempedges[5];//*
		R[0][0][0] = tempedges[6];//*
		R[0][0][1] = tempedges[7];//*
		R[0][0][2] = tempedges[8];//*
		R[1][0][2] = tempedges[9];//*
		R[1][1][2] = tempedges[10];//*
		R[1][2][2] = tempedges[11];//*
		R[3][0][0] = tempedges[12];//*
		R[3][0][1] = tempedges[13];//*
		R[3][0][2] = tempedges[14];//*
	}
	else {//counter
		R[5][0][0] = Rtemp[0][2];
		R[5][0][1] = Rtemp[1][2];
		R[5][0][2] = Rtemp[2][2];
		R[5][1][0] = Rtemp[0][1];
		R[5][1][1] = Rtemp[1][1];
		R[5][1][2] = Rtemp[2][1];
		R[5][2][0] = Rtemp[0][0];
		R[5][2][1] = Rtemp[1][0];
		R[5][2][2] = Rtemp[2][0];
		R[4][2][0] = tempedges[9];//*
		R[4][1][0] = tempedges[10];//*
		R[4][0][0] = tempedges[11];//*
		R[0][0][0] = tempedges[0];//*
		R[0][0][1] = tempedges[1];//*
		R[0][0][2] = tempedges[2];//*
		R[1][0][2] = tempedges[3];//*
		R[1][1][2] = tempedges[4];//*
		R[1][2][2] = tempedges[5];//*
		R[3][0][0] = tempedges[6];//*
		R[3][0][1] = tempedges[7];//*
		R[3][0][2] = tempedges[8];//*
	}
}
void moving(char R[6][3][3], vector<string> moves) {
	for (int i = 0; i < (int)moves.size(); ++i) {
		if ((int)moves[i].size() == 2) {
			if (moves[i][1] == '\'') {
				//cout << moves[i] << " entro apostrofe" << endl;
				if (moves[i][0] == 'U')giroU(R, 0);
				if (moves[i][0] == 'R')giroR(R, 0);
				if (moves[i][0] == 'F')giroF(R, 0);
				if (moves[i][0] == 'D')giroD(R, 0);
				if (moves[i][0] == 'L')giroL(R, 0);
				if (moves[i][0] == 'B')giroB(R, 0);
			}
			else {
				//cout << moves[i] << " entro doble" << endl;
				if (moves[i][0] == 'U') {
					giroU(R, 0); giroU(R, 0);
				}
				if (moves[i][0] == 'R') {
					giroR(R, 0); giroR(R, 0);
				}
				if (moves[i][0] == 'F') {
					giroF(R, 0); giroF(R, 0);
				}
				if (moves[i][0] == 'D') {
					giroD(R, 0); giroD(R, 0);
				}
				if (moves[i][0] == 'L') {
					giroL(R, 0); giroL(R, 0);
				}
				if (moves[i][0] == 'B') {
					giroB(R, 0); giroB(R, 0);
				}
			}
		}
		else {
			//cout << moves[i] << " entro normal" << endl;
			if (moves[i][0] == 'U')giroU(R, 1);
			if (moves[i][0] == 'R')giroR(R, 1);
			if (moves[i][0] == 'F')giroF(R, 1);
			if (moves[i][0] == 'D')giroD(R, 1);
			if (moves[i][0] == 'L')giroL(R, 1);
			if (moves[i][0] == 'B')giroB(R, 1);
		}
		//print(R);
		//cout << endl;
	}
}

std::string reverse(char R[6][3][3], int f) {
	std::string Cube;
	for (int i = 2; i > -1; --i) {/*UP*/
		for (int j = 2; j > -1; --j) {
			Cube.push_back(R[f][i][j]);
		}
	}
	int k = 0;
	for (int i = 0; i < 3; ++i) {/*UP*/
		for (int j = 0; j < 3; ++j) {
			R[f][i][j] = Cube[k]; ++k;
		}
	}
	return Cube;
}
std::string codificar(char R[6][3][3]) {
	std::string Cube;
	std::string temp = reverse(R, 3);
	for (int f = 0; f < 6; ++f) {
		for (int i = 0; i < 3; ++i) {/*UP*/
			for (int j = 0; j < 3; ++j) {
				Cube.push_back(R[f][i][j]);
			}
		}
	}
	return Cube;
}

std::string to_cube_not(std::vector<std::string> moves) {
	char R[6][3][3];
	for (int i = 0; i < 6; ++i) {
		//Tratar cara i
		if (i == 0)cara0(R[i][0]);
		if (i == 1)cara1(R[i][0]);
		if (i == 2)cara2(R[i][0]);
		if (i == 3)cara3(R[i][0]);
		if (i == 4)cara4(R[i][0]);
		if (i == 5)cara5(R[i][0]);
	}
	moving(R, moves);
	std::string s = codificar(R);
	return s;
}

std::string randomize() {
	srand(time(0));
	char R[6][3][3];
	for (int i = 0; i < 6; ++i) {
		//Tratar cara i
		if (i == 0)cara0(R[i][0]);
		if (i == 1)cara1(R[i][0]);
		if (i == 2)cara2(R[i][0]);
		if (i == 3)cara3(R[i][0]);
		if (i == 4)cara4(R[i][0]);
		if (i == 5)cara5(R[i][0]);
	}
	std::vector<std::string> moves = scramble(randomNum());
	moving(R, moves);
	std::string s = codificar(R);
	return s;
}