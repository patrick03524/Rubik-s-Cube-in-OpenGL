#include<iostream>
#include<string>
#include<vector> 
#include <cstdlib> 
#include <ctime> 
using namespace std;

int randomNum();
std::vector<std::string> scramble(int N_M);

void cara0(char* R);
void cara1(char* R);
void cara2(char* R);
void cara3(char* R);
void cara4(char* R);
void cara5(char* R);

void print(char R[6][3][3]);
void giroU(char R[6][3][3], int c);
void giroR(char R[6][3][3], int c);
void giroF(char R[6][3][3], int c);
void giroD(char R[6][3][3], int c);
void giroL(char R[6][3][3], int c);
void giroB(char R[6][3][3], int c);
void moving(char R[6][3][3], vector<string> moves);

std::string reverse(char R[6][3][3], int f);
std::string codificar(char R[6][3][3]);
std::string to_cube_not(std::vector<std::string> moves);
std::string randomize();
