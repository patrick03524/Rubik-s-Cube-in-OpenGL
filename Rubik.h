#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <string>
#include "Cube.h"
#include <iostream>
#include <queue>

using namespace std;

void ActualizarColores(vector<glm::vec3>&, vector<glm::vec3>);
GLfloat getOffsetColores(glm::vec3);
glm::vec2 getOffsetPosicion(int);

class Rubik { 
public:
	///------------------------Constructores------------------------///
	Rubik();
	Rubik(glm::vec3, GLfloat, GLfloat, GLuint, unsigned int);
	///------------------------Destructor------------------------///
	~Rubik();
	///------------------------Funciones------------------------///
	void Generador();
	void Dibujar();
	void Movimientos();
	void Desordenador(vector<string>);
	void Expandir(float);
	void ReinicioColores();
	void setColores(string);
	void setOffset(GLfloat);
	bool setAnimacion(string);
	void Solve(vector<string>);
	vector<string> getSolucion();
	void AgregarCentros(vector<int>&);
	void Mover();
	void ActualizarIndice();
	void getCentros(glm::vec3 [3][3][3]);
	void getTamanos(glm::vec3 [3][3][3]);
	unsigned int getPosicionDuple(string);
	GLfloat getAngulo();
	vector<int> getIndices();
	vector<glm::vec2> getTexturasXYZ(vector<glm::vec3>, vector<int>);
	glm::vec3 getVarColor(char);
	///------------------------Variables------------------------///
	vector<Cube*> cubitos;
	GLfloat midX;
	GLfloat midY;
	GLfloat midZ;
	GLfloat arista;
	GLfloat offset;
	GLuint shaderProgram;
	string colores;
	unsigned int texturauwu;
	bool Animacion;
	string AnimacionActual;
	int ContadorDeAnimacion;
	int TiempoDeAnimacion;
	vector<string> TempMovimientos;
	queue<string> ColaDesordenada;
	queue<string> ColaDeSolucion;
};