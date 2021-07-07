#include "Cube.h"
///------------------------Constructores------------------------///
Cube::Cube(GLfloat* vertex, GLfloat* colors, int* index, GLuint program) {
	vertexNum = 48;
	indexNum = 72;
	shaderProgram = program;
	vertices = vertex;
	colorCoords = colors;
	indices = index;
	iniciar();
}
Cube::Cube(glm::vec3 center, glm::vec3 sideLength, vector<glm::vec3> colors, vector<glm::vec2> textCoords, GLuint program, unsigned int textureNum) {
	vertexNum = 48;
	indexNum = 72;
	shaderProgram = program;
	centro_cubo = center;
	texture = textureNum;
	modelo = glm::mat4(1.0);
	modelPos = glGetUniformLocation(shaderProgram, "model");
	glm::vec3 side = sideLength;
	side.x /= 2;
	side.y /= 2;
	side.z /= 2;
	vector<glm::vec3> newColors(6, BLACK);
	newColors.insert(newColors.end(), colors.begin(), colors.end());
	vector<glm::vec2> newTextCoords;
	newTextCoords.reserve(48);

	for (int i = 0; i < 6; ++i) {
		newTextCoords.push_back(glm::vec2(0.0, 0.0));
		newTextCoords.push_back(glm::vec2(0.0, 0.01));
		newTextCoords.push_back(glm::vec2(0.01, 0.01));
		newTextCoords.push_back(glm::vec2(0.01, 0.0));
	}

	newTextCoords.insert(newTextCoords.end(), textCoords.begin(), textCoords.end());
	vertices = new GLfloat[144];
	colorCoords = new GLfloat[144];
	normal = new GLfloat[144];
	textureCoords = new GLfloat[96];
	indices = new int[72];
	GLfloat newVertices[144] = {
		center.x - side.x, center.y - side.y, center.z - side.z,
		center.x + side.x, center.y - side.y, center.z - side.z,
		center.x + side.x, center.y + side.y, center.z - side.z,
		center.x - side.x, center.y + side.y, center.z - side.z,
		center.x + side.x, center.y - side.y, center.z + side.z,
		center.x - side.x, center.y - side.y, center.z + side.z,
		center.x - side.x, center.y + side.y, center.z + side.z,
		center.x + side.x, center.y + side.y, center.z + side.z,
		center.x - side.x, center.y - side.y, center.z - side.z,
		center.x - side.x, center.y - side.y, center.z + side.z,
		center.x + side.x, center.y - side.y, center.z + side.z,
		center.x + side.x, center.y - side.y, center.z - side.z,
		center.x + side.x, center.y + side.y, center.z - side.z,
		center.x + side.x, center.y + side.y, center.z + side.z,
		center.x - side.x, center.y + side.y, center.z + side.z,
		center.x - side.x, center.y + side.y, center.z - side.z,
		center.x - side.x, center.y + side.y, center.z - side.z,
		center.x - side.x, center.y + side.y, center.z + side.z,
		center.x - side.x, center.y - side.y, center.z + side.z,
		center.x - side.x, center.y - side.y, center.z - side.z,
		center.x + side.x, center.y - side.y, center.z - side.z,
		center.x + side.x, center.y - side.y, center.z + side.z,
		center.x + side.x, center.y + side.y, center.z + side.z,
		center.x + side.x, center.y + side.y, center.z - side.z,
		center.x - (side.x - 0.05), center.y - (side.y - 0.05), center.z - side.z - 0.001,
		center.x + (side.x - 0.05), center.y - (side.y - 0.05), center.z - side.z - 0.001,
		center.x + (side.x - 0.05), center.y + (side.y - 0.05), center.z - side.z - 0.001,
		center.x - (side.x - 0.05), center.y + (side.y - 0.05), center.z - side.z - 0.001,
		center.x + (side.x - 0.05), center.y - (side.y - 0.05), center.z + side.z + 0.001,
		center.x - (side.x - 0.05), center.y - (side.y - 0.05), center.z + side.z + 0.001,
		center.x - (side.x - 0.05), center.y + (side.y - 0.05), center.z + side.z + 0.001,
		center.x + (side.x - 0.05), center.y + (side.y - 0.05), center.z + side.z + 0.001,
		center.x - (side.x - 0.05), center.y - side.y - 0.001, center.z - (side.z - 0.05),
		center.x - (side.x - 0.05), center.y - side.y - 0.001, center.z + (side.z - 0.05),
		center.x + (side.x - 0.05), center.y - side.y - 0.001, center.z + (side.z - 0.05),
		center.x + (side.x - 0.05), center.y - side.y - 0.001, center.z - (side.z - 0.05),
		center.x + (side.x - 0.05), center.y + side.y + 0.001, center.z - (side.z - 0.05),
		center.x + (side.x - 0.05), center.y + side.y + 0.001, center.z + (side.z - 0.05),
		center.x - (side.x - 0.05), center.y + side.y + 0.001, center.z + (side.z - 0.05),
		center.x - (side.x - 0.05), center.y + side.y + 0.001, center.z - (side.z - 0.05),
		center.x - side.x - 0.001, center.y + (side.y - 0.05), center.z - (side.z - 0.05),
		center.x - side.x - 0.001, center.y + (side.y - 0.05), center.z + (side.z - 0.05),
		center.x - side.x - 0.001, center.y - (side.y - 0.05), center.z + (side.z - 0.05),
		center.x - side.x - 0.001, center.y - (side.y - 0.05), center.z - (side.z - 0.05),
		center.x + side.x + 0.001, center.y - (side.y - 0.05), center.z - (side.z - 0.05),
		center.x + side.x + 0.001, center.y - (side.y - 0.05), center.z + (side.z - 0.05),
		center.x + side.x + 0.001, center.y + (side.y - 0.05), center.z + (side.z - 0.05),
		center.x + side.x + 0.001, center.y + (side.y - 0.05), center.z - (side.z - 0.05)
	};

	GLfloat newNormal[144] = {
		0.0f, 0.0f , -1.0f,
		0.0f, 0.0f , -1.0f,
		0.0f, 0.0f , -1.0f,
		0.0f, 0.0f , -1.0f,
		0.0f, 0.0f , 1.0f,
		0.0f, 0.0f , 1.0f,
		0.0f, 0.0f , 1.0f,
		0.0f, 0.0f , 1.0f,
		0.0f, -1.0f , 0.0f,
		0.0f, -1.0f , 0.0f,
		0.0f, -1.0f , 0.0f,
		0.0f, -1.0f , 0.0f,
		0.0f, 1.0f , 0.0f,
		0.0f, 1.0f , 0.0f,
		0.0f, 1.0f , 0.0f,
		0.0f, 1.0f , 0.0f,
		-1.0f, 0.0f , 0.0f,
		-1.0f, 0.0f , 0.0f,
		-1.0f, 0.0f , 0.0f,
		-1.0f, 0.0f , 0.0f,
		1.0f, 0.0f , 0.0f,
		1.0f, 0.0f , 0.0f,
		1.0f, 0.0f , 0.0f,
		1.0f, 0.0f , 0.0f,
		0.0f, 0.0f , -1.0f,
		0.0f, 0.0f , -1.0f,
		0.0f, 0.0f , -1.0f,
		0.0f, 0.0f , -1.0f,
		0.0f, 0.0f , 1.0f,
		0.0f, 0.0f , 1.0f,
		0.0f, 0.0f , 1.0f,
		0.0f, 0.0f , 1.0f,
		0.0f, -1.0f , 0.0f,
		0.0f, -1.0f , 0.0f,
		0.0f, -1.0f , 0.0f,
		0.0f, -1.0f , 0.0f,
		0.0f, 1.0f , 0.0f,
		0.0f, 1.0f , 0.0f,
		0.0f, 1.0f , 0.0f,
		0.0f, 1.0f , 0.0f,
		-1.0f, 0.0f , 0.0f,
		-1.0f, 0.0f , 0.0f,
		-1.0f, 0.0f , 0.0f,
		-1.0f, 0.0f , 0.0f,
		1.0f, 0.0f , 0.0f,
		1.0f, 0.0f , 0.0f,
		1.0f, 0.0f , 0.0f,
		1.0f, 0.0f , 0.0f
	};

	GLubyte newIndices[72] = {
		0, 1, 2,
		0 ,2 ,3,
		4 ,5 ,6,
		4 ,6 ,7,
		8 ,9,10,
		8 ,10 ,11,
		12 ,13 ,14,
		12 ,14 ,15,
		16 ,17 ,18,
		16 ,18 ,19,
		20 ,21 ,22,
		20 ,22 ,23,
		24, 25, 26,
		24 ,26 ,27,
		28 ,29 ,30,
		28 ,30 ,31,
		32 ,33,34,
		32 ,34 ,35,
		36 ,37 ,38,
		36 ,38 ,39,
		40 ,41 ,42,
		40 ,42 ,43,
		44 ,45 ,46,
		44 ,46 ,47
	};

	for (int i = 0; i < 72; ++i) {
		indices[i] = newIndices[i];
		vertices[i * 2] = newVertices[i * 2];
		vertices[i * 2 + 1] = newVertices[i * 2 + 1];
		normal[i * 2] = newNormal[i * 2];
		normal[i * 2 + 1] = newNormal[i * 2 + 1];
	}

	for (int i = 0; i < 144; i += 3) {
		colorCoords[i] = newColors[i / 12].x;
		colorCoords[i + 1] = newColors[i / 12].y;
		colorCoords[i + 2] = newColors[i / 12].z;
	}

	for (int i = 0; i < 48; ++i) {
		textureCoords[i * 2] = newTextCoords[i].x;
		textureCoords[i * 2 + 1] = newTextCoords[i].y;
	}
	iniciar();
	
	delete[] vertices;
	delete[] colorCoords;
	delete[] indices;
	delete[] normal;
	delete[] textureCoords;
}
///------------------------Destructor------------------------///
Cube::~Cube() {
	delete vertices;
	delete colorCoords;
	delete indices;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(3, VBOs);
	glDeleteBuffers(1, &EBO);
}
///------------------------Funciones------------------------///
void Cube::iniciar() {
	////////////CLASICO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(4, VBOs);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertexNum * 3, vertices, GL_STATIC_DRAW);

	///////////////////////////////////////////////////////////EnableVertexAttribArray_1
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]); ////Buffer VBO_1
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorCoords[0]) * vertexNum * 3, colorCoords, GL_STATIC_DRAW);
	///////////////////////////////////////////////////////////EnableVertexAttribArray_1
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);////Buffer VBO_2
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoords[0]) * vertexNum * 2, textureCoords, GL_STATIC_DRAW);
	///////////////////////////////////////////////////////////EnableVertexAttribArray_2
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);////Buffer VBO_3
	glBufferData(GL_ARRAY_BUFFER, sizeof(normal[0]) * vertexNum * 3, normal, GL_STATIC_DRAW);
	///////////////////////////////////////////////////////////EnableVertexAttribArray_3
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); ////Buffer EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indexNum, indices, GL_STATIC_DRAW);
}

void Cube::dibujar() {
	glBindVertexArray(VAO);
	glUseProgram(shaderProgram);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniformMatrix4fv(modelPos, 1, GL_FALSE, &modelo[0][0]);
	glDrawElements(GL_TRIANGLES, indexNum, GL_UNSIGNED_INT, 0);
}

void Cube::rotate(GLfloat angulo, int eje) {
	glm::vec3 direccion_rot;
	switch (eje) {
	case 0:
		direccion_rot = glm::vec3(1.0, 0.0, 0.0);
		break;
	case 1:
		direccion_rot = glm::vec3(0.0, 1.0, 0.0);
		break;
	case 2:
		direccion_rot = glm::vec3(0.0, 0.0, 1.0);
		break;
	}
	modelo = glm::rotate(glm::mat4(1.0f), angulo, direccion_rot) * modelo;
	centro_cubo = glm::mat3(glm::rotate(glm::mat4(1.0f), angulo, direccion_rot)) * centro_cubo;
}

void Cube::traslate(glm::vec3 traslacion) {
	modelo = glm::translate(glm::mat4(1.0f), traslacion) * modelo;
	centro_cubo = glm::mat3(glm::translate(glm::mat4(1.0f), traslacion)) * centro_cubo;
}

void Cube::Alejarse(glm::vec3 centro, float distancia) {
	glm::vec3 direccion_alej = centro_cubo - centro;
	if (direccion_alej.x > 0) {
		direccion_alej.x = 1;
	}
	if (direccion_alej.y > 0) {
		direccion_alej.y = 1;
	}
	if (direccion_alej.z > 0) {
		direccion_alej.z = 1;
	}
	modelo = glm::translate(glm::mat4(1.0), direccion_alej * distancia) * modelo;
	centro_cubo = glm::mat3(glm::translate(glm::mat4(1.0), direccion_alej * distancia)) * centro_cubo;
}

