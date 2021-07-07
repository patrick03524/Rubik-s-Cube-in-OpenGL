#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 7776

#define RED glm::vec3(0.81,0.8,0.8)
#define GREEN glm::vec3(0.79,0.8,0.8)
#define BLUE glm::vec3(0.8,0.81,0.8)

#define WHITE glm::vec3(0.8,0.79,0.8)
#define YELLOW glm::vec3(0.8,0.8,0.81)
#define ORANGE glm::vec3(0.8,0.8,0.79)
#define BLACK glm::vec3(0.0,0.0,0.0)

#define CUBE_UP {11, 14,17, 16, 15, 12, 9, 10}
#define CUBE_DOWN {18, 21, 24, 25, 26, 23, 20, 19}
#define CUBE_RIGHT {15, 16, 17, 8, 26, 25, 24, 6}
#define CUBE_LEFT {11, 10, 9, 3, 18, 19, 20, 5}
#define CUBE_FRONT {9, 12, 15, 6, 24, 21, 18, 3}
#define CUBE_BACK {17, 14, 11, 5, 20, 23, 26, 8}
#define nullTexture {glm::vec2(0.0,0.0),glm::vec2(0.1,0.0),glm::vec2(0.0,0.1),glm::vec2(0.1,0.1)}

class Cube {
public:
    ///------------------------Constructores------------------------///
    Cube(GLfloat*, GLfloat*, int*, GLuint);
    Cube(glm::vec3, glm::vec3, vector<glm::vec3>, vector<glm::vec2>, GLuint, unsigned int);
    ///------------------------Destructor------------------------///
    ~Cube();
    ///------------------------Funciones------------------------///
    void iniciar();
    void dibujar();
    void rotate(GLfloat, int);
    void traslate(glm::vec3);
    void Alejarse(glm::vec3, float); 
    ///------------------------Variables------------------------///
    GLfloat* vertices, * colorCoords, * textureCoords, * normal;
    GLuint modelPos;
    glm::mat4 modelo;
    glm::vec3 centro_cubo;
    unsigned int shaderProgram, texture;
    unsigned int VAO, VBOs[3], EBO;
    unsigned int vertexNum, indexNum;
    int orientation;
    int* indices;
};
