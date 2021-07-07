#include <iostream>
#include "Rubik.h"

using namespace std;
///------------------------Constructores------------------------///
Rubik::Rubik() {}

Rubik::Rubik(glm::vec3 mid_, GLfloat arista_, GLfloat offset_, GLuint shaderProgram_, unsigned int numTexturauwu) :cubitos(27, nullptr), Animacion(false), ContadorDeAnimacion(0), TiempoDeAnimacion(30), texturauwu(numTexturauwu) {
	this->midX = mid_.x;
	this->midY = mid_.y;
	this->midZ = mid_.z;
	this->arista = arista_;
	this->offset = offset_;
	this->shaderProgram = shaderProgram_;

	ReinicioColores();
}
///------------------------Destructor------------------------///
Rubik::~Rubik() {
	for (Cube* cubito : cubitos) {
		delete cubito;
	}
}
///------------------------Funciones------------------------///
void Rubik::Generador() {
	vector<glm::vec3> auxColores(6, glm::vec3(0.1));
	glm::vec3 tamDistribucion[3][3][3];
	getTamanos(tamDistribucion);
	glm::vec3 centros[3][3][3];
	getCentros(centros);
	/// F -> Cara Amarila
	/// L -> Cara Azul
	/// B -> Cara Blanca
	/// R -> Cara Verde
	/// U -> Cara Naranja
	/// D -> Cara Roja
	ActualizarColores(auxColores, { BLACK,BLACK,BLACK,BLACK,BLACK,getVarColor(colores[getPosicionDuple("F5")]) });
	cubitos[0] = new Cube(centros[2][1][1], tamDistribucion[2][1][1], auxColores, getTexturasXYZ(auxColores, { 0,0,0,0,0,5 }), shaderProgram, texturauwu);//F5
	ActualizarColores(auxColores, { BLACK,BLACK,BLACK,BLACK,BLACK,BLACK });
	cubitos[1] = new Cube(centros[1][1][1], tamDistribucion[1][1][1], auxColores, getTexturasXYZ(auxColores, { 0,0,0,0,0,0 }), shaderProgram, texturauwu);//0
	ActualizarColores(auxColores, { BLACK,BLACK,BLACK,BLACK,getVarColor(colores[getPosicionDuple("B5")]),BLACK });
	cubitos[2] = new Cube(centros[0][1][1], tamDistribucion[0][1][1], auxColores, getTexturasXYZ(auxColores, { 0,0,0,0,5,0 }), shaderProgram, texturauwu);//B5
	ActualizarColores(auxColores, { BLACK,BLACK,getVarColor(colores[getPosicionDuple("L6")]),BLACK,BLACK,getVarColor(colores[getPosicionDuple("F4")]) });
	cubitos[3] = new Cube(centros[2][0][1], tamDistribucion[2][0][1], auxColores, getTexturasXYZ(auxColores, { 0,0,6,0,0,4 }), shaderProgram, texturauwu);//F4-L6
	ActualizarColores(auxColores, { BLACK,BLACK,getVarColor(colores[getPosicionDuple("L5")]),BLACK,BLACK,BLACK });
	cubitos[4] = new Cube(centros[1][0][1], tamDistribucion[1][0][1], auxColores, getTexturasXYZ(auxColores, { 0,0,5,0,0,0 }), shaderProgram, texturauwu);//L5
	ActualizarColores(auxColores, { BLACK,BLACK,getVarColor(colores[getPosicionDuple("L4")]),BLACK,getVarColor(colores[getPosicionDuple("B6")]),BLACK });
	cubitos[5] = new Cube(centros[0][0][1], tamDistribucion[0][0][1], auxColores, getTexturasXYZ(auxColores, { 0,0,4,0,6,0 }), shaderProgram, texturauwu);//B6-L4
	ActualizarColores(auxColores, { BLACK,BLACK,BLACK,getVarColor(colores[getPosicionDuple("R4")]),BLACK,getVarColor(colores[getPosicionDuple("F6")]) });
	cubitos[6] = new Cube(centros[2][2][1], tamDistribucion[2][2][1], auxColores, getTexturasXYZ(auxColores, { 0,0,0,4,0,6 }), shaderProgram, texturauwu);//F6-R4
	ActualizarColores(auxColores, { BLACK,BLACK,BLACK,getVarColor(colores[getPosicionDuple("R5")]),BLACK,BLACK });
	cubitos[7] = new Cube(centros[1][2][1], tamDistribucion[1][2][1], auxColores, getTexturasXYZ(auxColores, { 0,0,0,5,0,0 }), shaderProgram, texturauwu);//R5
	ActualizarColores(auxColores, { BLACK,BLACK,BLACK,getVarColor(colores[getPosicionDuple("R6")]),getVarColor(colores[getPosicionDuple("B4")]),BLACK });
	cubitos[8] = new Cube(centros[0][2][1], tamDistribucion[0][2][1], auxColores, getTexturasXYZ(auxColores, { 0,0,0,6,4,0 }), shaderProgram, texturauwu);//R6-B4
	ActualizarColores(auxColores, { BLACK,getVarColor(colores[getPosicionDuple("U7")]),getVarColor(colores[getPosicionDuple("L3")]),BLACK,BLACK,getVarColor(colores[getPosicionDuple("F1")]) });																																						 //---
	cubitos[9] = new Cube(centros[2][0][2], tamDistribucion[2][0][2], auxColores, getTexturasXYZ(auxColores, { 0,7,3,0,0,1 }), shaderProgram, texturauwu);//F1-L3-U7
	ActualizarColores(auxColores, { BLACK,getVarColor(colores[getPosicionDuple("U4")]),getVarColor(colores[getPosicionDuple("L2")]),BLACK,BLACK,BLACK });
	cubitos[10] = new Cube(centros[1][0][2], tamDistribucion[1][0][2], auxColores, getTexturasXYZ(auxColores, { 0,4,2,0,0,0 }), shaderProgram, texturauwu);//L2-U4
	ActualizarColores(auxColores, { BLACK,getVarColor(colores[getPosicionDuple("U1")]),getVarColor(colores[getPosicionDuple("L1")]),BLACK,getVarColor(colores[getPosicionDuple("B3")]),BLACK });
	cubitos[11] = new Cube(centros[0][0][2], tamDistribucion[0][0][2], auxColores, getTexturasXYZ(auxColores, { 0,1,1,0,3,0 }), shaderProgram, texturauwu);//B3-L1-U1
	ActualizarColores(auxColores, { BLACK,getVarColor(colores[getPosicionDuple("U8")]),BLACK,BLACK,BLACK,getVarColor(colores[getPosicionDuple("F2")]) });
	cubitos[12] = new Cube(centros[2][1][2], tamDistribucion[2][1][2], auxColores, getTexturasXYZ(auxColores, { 0,8,0,0,0,2 }), shaderProgram, texturauwu);//F2-U8
	ActualizarColores(auxColores, { BLACK,getVarColor(colores[getPosicionDuple("U5")]),BLACK,BLACK,BLACK,BLACK });
	cubitos[13] = new Cube(centros[1][1][2], tamDistribucion[1][1][2], auxColores, getTexturasXYZ(auxColores, { 0,5,0,0,0,0 }), shaderProgram, texturauwu);//U5
	ActualizarColores(auxColores, { BLACK,getVarColor(colores[getPosicionDuple("U2")]),BLACK,BLACK,getVarColor(colores[getPosicionDuple("B2")]),BLACK });
	cubitos[14] = new Cube(centros[0][1][2], tamDistribucion[0][1][2], auxColores, getTexturasXYZ(auxColores, { 0,2,0,0,2,0 }), shaderProgram, texturauwu);//U2-B8
	ActualizarColores(auxColores, { BLACK,getVarColor(colores[getPosicionDuple("U9")]),BLACK,getVarColor(colores[getPosicionDuple("R1")]),BLACK,getVarColor(colores[getPosicionDuple("F3")]) });
	cubitos[15] = new Cube(centros[2][2][2], tamDistribucion[2][2][2], auxColores, getTexturasXYZ(auxColores, { 0,9,0,1,0,3 }), shaderProgram, texturauwu);//F3-U9-R1
	ActualizarColores(auxColores, { BLACK,getVarColor(colores[getPosicionDuple("U6")]),BLACK,getVarColor(colores[getPosicionDuple("R2")]),BLACK,BLACK });
	cubitos[16] = new Cube(centros[1][2][2], tamDistribucion[1][2][2], auxColores, getTexturasXYZ(auxColores, { 0,6,0,2,0,0 }), shaderProgram, texturauwu);//R2-U8
	ActualizarColores(auxColores, { BLACK,getVarColor(colores[getPosicionDuple("U3")]),BLACK,getVarColor(colores[getPosicionDuple("R3")]),getVarColor(colores[getPosicionDuple("B1")]),BLACK });
	cubitos[17] = new Cube(centros[0][2][2], tamDistribucion[0][2][2], auxColores, getTexturasXYZ(auxColores, { 0,3,0,3,1,0 }), shaderProgram, texturauwu);//R3-B1-U3
	ActualizarColores(auxColores, { getVarColor(colores[getPosicionDuple("D1")]),BLACK,getVarColor(colores[getPosicionDuple("L9")]),BLACK,BLACK,getVarColor(colores[getPosicionDuple("F7")]) });
	cubitos[18] = new Cube(centros[2][0][0], tamDistribucion[2][0][0], auxColores, getTexturasXYZ(auxColores, { 1,0,9,0,0,7 }), shaderProgram, texturauwu);//F7-L9-D1
	ActualizarColores(auxColores, { getVarColor(colores[getPosicionDuple("D4")]),BLACK,getVarColor(colores[getPosicionDuple("L8")]),BLACK,BLACK,BLACK });
	cubitos[19] = new Cube(centros[1][0][0], tamDistribucion[1][0][0], auxColores, getTexturasXYZ(auxColores, { 4,0,8,0,0,0 }), shaderProgram, texturauwu);//L8-D2
	ActualizarColores(auxColores, { getVarColor(colores[getPosicionDuple("D7")]),BLACK,getVarColor(colores[getPosicionDuple("L7")]),BLACK,getVarColor(colores[getPosicionDuple("B9")]),BLACK });
	cubitos[20] = new Cube(centros[0][0][0], tamDistribucion[0][0][0], auxColores, getTexturasXYZ(auxColores, { 7,0,7,0,9,0 }), shaderProgram, texturauwu);//L7-B9-D3
	ActualizarColores(auxColores, { getVarColor(colores[getPosicionDuple("D2")]),BLACK,BLACK,BLACK,BLACK,getVarColor(colores[getPosicionDuple("F8")]) });
	cubitos[21] = new Cube(centros[2][1][0], tamDistribucion[2][1][0], auxColores, getTexturasXYZ(auxColores, { 2,0,0,0,0,8 }), shaderProgram, texturauwu);//F8-D2
	ActualizarColores(auxColores, { getVarColor(colores[getPosicionDuple("D5")]),BLACK,BLACK,BLACK,BLACK,BLACK });
	cubitos[22] = new Cube(centros[1][1][0], tamDistribucion[1][1][0], auxColores, getTexturasXYZ(auxColores, { 5,0,0,0,0,0 }), shaderProgram, texturauwu);//D5
	ActualizarColores(auxColores, { getVarColor(colores[getPosicionDuple("D8")]),BLACK,BLACK,BLACK,getVarColor(colores[getPosicionDuple("B8")]),BLACK });
	cubitos[23] = new Cube(centros[0][1][0], tamDistribucion[0][1][0], auxColores, getTexturasXYZ(auxColores, { 8,0,0,0,8,0 }), shaderProgram, texturauwu);//B8-D2
	ActualizarColores(auxColores, { getVarColor(colores[getPosicionDuple("D3")]),BLACK,BLACK,getVarColor(colores[getPosicionDuple("R7")]),BLACK,getVarColor(colores[getPosicionDuple("F9")]) });
	cubitos[24] = new Cube(centros[2][2][0], tamDistribucion[2][2][0], auxColores, getTexturasXYZ(auxColores, { 3,0,0,7,0,9 }), shaderProgram, texturauwu);//F9-R7-D3
	ActualizarColores(auxColores, { getVarColor(colores[getPosicionDuple("D6")]),BLACK,BLACK,getVarColor(colores[getPosicionDuple("R8")]),BLACK,BLACK });
	cubitos[25] = new Cube(centros[1][2][0], tamDistribucion[1][2][0], auxColores, getTexturasXYZ(auxColores, { 6,0,0,8,0,0 }), shaderProgram, texturauwu);//D6-R8
	ActualizarColores(auxColores, { getVarColor(colores[getPosicionDuple("D9")]),BLACK,BLACK,getVarColor(colores[getPosicionDuple("R9")]),getVarColor(colores[getPosicionDuple("B7")]),BLACK });
	cubitos[26] = new Cube(centros[0][2][0], tamDistribucion[0][2][0], auxColores, getTexturasXYZ(auxColores, { 9,0,0,9,7,0 }), shaderProgram, texturauwu);//R9-B7-D1

	for (auto cubito : cubitos) {
		cubito->traslate(-centros[1][1][1]);
	}
	midX = centros[1][1][1].x;
	midY = centros[1][1][1].y;
	midZ = centros[1][1][1].z;
}

void Rubik::Dibujar() {
	for (Cube* cubito : cubitos) {
		cubito->dibujar();
	}
}

void Rubik::Movimientos() {
	if (!ColaDesordenada.empty()) {
		if (!Animacion) {
			AnimacionActual = ColaDesordenada.front();
			setAnimacion(AnimacionActual);
			ColaDesordenada.pop();
		}
	}
	if (!ColaDeSolucion.empty()) {
		if (!Animacion) {
			AnimacionActual = ColaDeSolucion.front();
			setAnimacion(AnimacionActual);
			ColaDeSolucion.pop();
		}
	}
	if (ContadorDeAnimacion == TiempoDeAnimacion) {
		Animacion = false;
		ActualizarIndice();
		ContadorDeAnimacion++;
	}
	if (Animacion) {
		Mover();
		ContadorDeAnimacion++;
	}
}

void Rubik::Desordenador(vector<string> vecDesorden_) {
	TempMovimientos = vecDesorden_;	//Guardo los movimientos para usarlos para resolver
	for (string move : vecDesorden_) {
		ColaDesordenada.push(move);
	}
}

void Rubik::Expandir(float distancia_) {
	for (Cube* cubito : cubitos) {
		if (cubito != cubitos[1])
			cubito->Alejarse(glm::vec3(midX, midY, midZ), distancia_);
	}
}

void Rubik::ReinicioColores() {
	this->colores = "UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB";
}

void Rubik::setColores(string colores_) {
	this->colores = colores_;
}

void Rubik::setOffset(GLfloat offset_) {
	this->offset = offset_;
}

bool Rubik::setAnimacion(string movimiento_) {
	if (!Animacion) {
		AnimacionActual = movimiento_;
		Animacion = true;
		ContadorDeAnimacion = 0;
		if (AnimacionActual.length() == 2 && AnimacionActual[1] == '2')
			TiempoDeAnimacion = 60;
		else
			TiempoDeAnimacion = 30;
		return true;
	}
	return false;
}

void Rubik::Solve(vector<string> solucion_) {
	for (string move : solucion_) {
		ColaDeSolucion.push(move);
	}
}

vector<string> Rubik::getSolucion() {
	return TempMovimientos;
}

void Rubik::AgregarCentros(vector<int>& indices_) {
	switch (AnimacionActual[0]) {
	case 'U':
		indices_.push_back(13);
		break;
	case 'D':
		indices_.push_back(22);
		break;
	case 'R':
		indices_.push_back(7);
		break;
	case 'L':
		indices_.push_back(4);
		break;
	case 'F':
		indices_.push_back(0);
		break;
	case 'B':
		indices_.push_back(2);
		break;
	}
}

void Rubik::Mover() {
	vector<int> camadas = getIndices();
	AgregarCentros(camadas);
	int axis;
	GLfloat angulo = getAngulo();
	angulo *= glm::pi<float>() / 60;
	switch (AnimacionActual[0]) {
	case 'U':
		axis = 2;
		break;
	case 'D':
		axis = 2;
		break;
	case 'R':
		axis = 1;
		break;
	case 'L':
		axis = 1;
		break;
	case 'F':
		axis = 0;
		break;
	case 'B':
		axis = 0;
		break;
	}
	if (AnimacionActual.length() == 2 && AnimacionActual[1] == '\'')
		angulo *= -1;
	for (int i : camadas) {
		cubitos[i]->rotate(angulo, axis);
	}
}

void Rubik::ActualizarIndice() {
	int offset = 6;
	if (AnimacionActual.length() == 2 && AnimacionActual[1] == '\'')
		offset = 2;
	if (AnimacionActual.length() == 2 && AnimacionActual[1] == '2')
		offset = 4;

	vector<int> camadas = getIndices();
	vector<Cube*> cubitosOriginales = cubitos;
	for (size_t i = 0, top = camadas.size(); i < top; ++i) {
		cubitos[camadas[i]] = cubitosOriginales[camadas[(i + offset) % top]];
	}
}

void Rubik::getCentros(glm::vec3 cubo[3][3][3]) {
	glm::vec3 tamDistribucion[3][3][3];
	getTamanos(tamDistribucion);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				cubo[i][j][k].x = tamDistribucion[i][j][k].x / 2;
				if (i > 0)
					cubo[i][j][k].x += cubo[i - 1][j][k].x + tamDistribucion[i - 1][j][k].x / 2 + offset;

				cubo[i][j][k].y = tamDistribucion[i][j][k].y / 2;
				if (j > 0)
					cubo[i][j][k].y += cubo[i][j - 1][k].y + tamDistribucion[i][j - 1][k].y / 2 + offset;

				cubo[i][j][k].z = tamDistribucion[i][j][k].z / 2;
				if (k > 0)
					cubo[i][j][k].z += cubo[i][j][k - 1].z + tamDistribucion[i][j][k - 1].z / 2 + offset;
			}
		}
	}
}

void Rubik::getTamanos(glm::vec3 cubo[3][3][3]) {
	float cambio = 0.5;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubo[0][i][j].x = cambio * 3 * arista;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubo[1][i][j].x = cambio * 3 * arista;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubo[2][i][j].x = cambio * 3 * arista;
		}
	}


	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubo[i][0][j].y = cambio * 3 * arista;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubo[i][1][j].y = cambio * 3 * arista;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubo[i][2][j].y = cambio * 3 * arista;
		}
	}


	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubo[i][j][0].z = cambio * 3 * arista;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubo[i][j][1].z = cambio * 3 * arista;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cubo[i][j][2].z = cambio * 3 * arista;
		}
	}
}

unsigned int Rubik::getPosicionDuple(string duple_) {
	int lado, num;
	switch (duple_[0]) {
	case 'F':
		lado = 2;
		break;
	case 'D':
		lado = 3;
		break;
	case 'U':
		lado = 0;
		break;
	case 'B':
		lado = 5;
		break;
	case 'R':
		lado = 1;
		break;
	case 'L':
		lado = 4;
		break;
	}
	num = duple_[1] - '0';
	return lado * 9 + num - 1;
}

GLfloat Rubik::getAngulo() {
	float angulo;
	switch (AnimacionActual[0]) {
	case 'U':
		angulo = -1.0;
		break;
	case 'D':
		angulo = 1.0;
		break;
	case 'R':
		angulo = -1.0;
		break;
	case 'L':
		angulo = 1.0;
		break;
	case 'F':
		angulo = -1.0;
		break;
	case 'B':
		angulo = 1.0;
		break;
	}
	return angulo;
}

vector<int> Rubik::getIndices() {
	vector<int> camadas;
	switch (AnimacionActual[0]) {
	case 'U':
		camadas = CUBE_UP;
		break;
	case 'D':
		camadas = CUBE_DOWN;
		break;
	case 'R':
		camadas = CUBE_RIGHT;
		break;
	case 'L':
		camadas = CUBE_LEFT;
		break;
	case 'F':
		camadas = CUBE_FRONT;
		break;
	case 'B':
		camadas = CUBE_BACK;
		break;
	}
	return camadas;
}

vector<glm::vec2> Rubik::getTexturasXYZ(vector<glm::vec3> colores_, vector<int> posicion_) {
	vector<glm::vec2> coordenadas;
	glm::vec2 offset;
	coordenadas.reserve(24);
	GLfloat offsetX, offsetY, varOffset = 1.0 / 18.0;
	for (size_t i = 0, top = colores_.size(); i < top; ++i) {
		if (colores_[i] != BLACK) {
			offsetX = getOffsetColores(colores_[i]);
			offsetY = 0;
			offset = getOffsetPosicion(posicion_[i]);
			offsetX += offset.x;
			offsetY += offset.y;
			coordenadas.push_back(glm::vec2(offsetX, offsetY + varOffset * 6));
			coordenadas.push_back(glm::vec2(offsetX, offsetY));
			coordenadas.push_back(glm::vec2(offsetX + varOffset, offsetY));
			coordenadas.push_back(glm::vec2(offsetX + varOffset, offsetY + varOffset * 6));
		}
		else {
			coordenadas.push_back(glm::vec2(0.0, 0.0));
			coordenadas.push_back(glm::vec2(0.0, 0.01));
			coordenadas.push_back(glm::vec2(0.01, 0.01));
			coordenadas.push_back(glm::vec2(0.01, 0.0));
		}

	}
	return coordenadas;
}

glm::vec3 Rubik::getVarColor(char c) {
	glm::vec3 color;
	switch (c) {
	case 'F':
		color = YELLOW;
		break;
	case 'D':
		color = GREEN;
		break;
	case 'U':
		color = BLUE;
		break;
	case 'B':
		color = WHITE;
		break;
	case 'R':
		color = ORANGE;
		break;
	case 'L':
		color = RED;
		break;
	}
	return color;
}

void ActualizarColores(vector<glm::vec3>& colores_, vector<glm::vec3> coloresNuevos_) {
	for (size_t i = 0, top = coloresNuevos_.size(); i < top; ++i) {
		colores_[i] = coloresNuevos_[i];
	}
}

GLfloat getOffsetColores(glm::vec3 color_) {
	GLfloat offset, varColor = 1.0 / 6.0;

	if (color_ == YELLOW) {
		offset = 0.0;
	}
	else if (color_ == ORANGE) {
		offset = varColor;
	}
	else if (color_ == BLUE) {
		offset = varColor * 2;
	}
	else if (color_ == WHITE) {
		offset = varColor * 3;
	}
	else if (color_ == RED) {
		offset = varColor * 4;
	}
	else if (color_ == GREEN) {
		offset = varColor * 5;
	}
	return offset;
}

glm::vec2 getOffsetPosicion(int posicion_) {
	float varOffset = 1.0 / 18.0;
	return glm::vec2(varOffset * ((posicion_ - 1) % 3), varOffset * ((posicion_ - 1) / 3) * 6);
}