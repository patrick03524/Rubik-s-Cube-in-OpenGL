/*
	//////////////////////////////////////////////////////
	CURSO: Computacion Grafica
	GRUPO: CComp7-1
	FINAL PRACTICO DE COMPUTACION GRAFICA
	Integrantes del Grupo:
		-Patrick Xavier Marquez Choque
		-Iñigo Manuel Diez Canseco Fuentes 
		-Oscar Andree Mendoza Alejandro 
	INSTRUCCIONES SOLO COMPILAR EL PROYECTO
	COLOCAR LA TEXTURAS EN UNA CARPETA EN EL DISCO D
	AL COMPILAR EL PROYECTO SE GENERARA UN CUBO EN EL CENTRO DE LA PANTALLA 
	TECLA Q: Movimiento R en sentido horario
	TECLA W: Movimiento L en sentido horario
	TECLA E: Movimiento U en sentido horario
	TECLA R: Movimiento D en sentido horario
	TECLA T: Movimiento F en sentido horario
	TECLA Y: Movimiento B en sentido horario
	TECLA Z: Resolvera el cubo que se transformo con los movimientos clasicos del Cubo de Rubik
	Tecla X: Desordenara aleatoriamente el cubo de Rubik
	Tecla C: Resolvera el cubo de Rubik desordenado aleatoriamente al presionar la tecla X
	Tecla SPACE: Realizara la Animacion de la respiracion del cubo de Rubik
	Tecla N: Realizara la Animacion de Expandir el Cubo
	Tecla M: Realizara la Animacion de Contraer el Cubo
	Tecla B: El cubo de Rubik cambiara de textura
	//////////////////////////////////////////////////////
*/
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "Rubik.h"
#include "Solver/random.h"
#include "Solver/solve.h"
#include "stb_image.h"

using namespace std;
///------------------------Funciones------------------------///
void framebuffer_size_callback(GLFWwindow* window, int w, int h);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
void printComands();
///------------------------Variables------------------------///
string rutaImagen = "";

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
///------------------------Coordenadas------------------------///
GLfloat centerX = 0.0f,
centerY = 0.0f,
centerZ = 0.0f;
GLfloat arista = 0.3;	//tamaño de la arista de los cubitos
GLfloat offset = 0.00;	//tamaño de la distancia entre cubos
GLuint shader;
///------------------------Objeto Cubo------------------------///
Rubik* rubikCube;
///------------------------Matrices------------------------///
glm::mat4 projection;
glm::mat4 modelview;
glm::vec3 cameraCenter(0, 0, 0);
glm::vec3 cameraUp(0.0, 0.0, 1.0);
glm::vec3 cameraEye(1.0, -5.0, 1.0);
///------------------------Utilidad------------------------///
int cont = 7;
bool text = true;
///------------------------Shader------------------------///
GLuint projectionPos;
GLuint modelviewPos;
GLuint viewPosPos;
///------------------------Mouse------------------------///
bool firstMouse = true;
float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
///------------------------Movimientos------------------------///
vector<string> cuboga;
///------------------------Vertex-Shader------------------------///
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"layout (location = 2) in vec2 aTexCoord;\n"
"layout (location = 3) in vec3 aNormal;\n"
"out vec3 Color;\n"
"out vec2 TexCoord;\n"
"out vec3 FragPos;\n"
"out vec3 Normal;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"	FragPos = vec3(model * vec4(aPos,1.0));\n"
"	Normal = mat3(transpose(inverse(model))) * aNormal;\n"
"   gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
"	Color = aColor;\n"
"	TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
"}\n\0";
///------------------------Fragment-Shader------------------------///
const char* fragmentShaderSource = "#version 330 core\n"
"in vec3 Color;\n"
"in vec2 TexCoord;\n"
"in vec3 FragPos;\n"
"in vec3 Normal;\n"
"out vec4 fragColor;\n"
"uniform sampler2D texture1;\n"
"uniform vec3 viewPos;\n"
"void main(void)\n"
"{\n"
"	vec3 result = Color;\n"
"   fragColor = texture(texture1, TexCoord) * vec4(result, 1.0f);\n"
"}\n\0";

int main(int agrc, char* argv[]) {
	std::cout << "//////////////////////////////////////////////////////" << endl;
	std::cout << "CURSO: Computacion Grafica" << std::endl;
	std::cout << "GRUPO: CComp7-1" << std::endl;
	std::cout << "FINAL PRACTICO DE COMPUTACION GRAFICA" << std::endl;
	std::cout << "Integrantes del Grupo:" << endl;
	std::cout << "	-Patrick Xavier Marquez Choque" << endl;
	std::cout << "	-Inigo Manuel Diez Canseco Fuentes" << endl;
	std::cout << "	-Oscar Andree Mendoza Alejandro" << endl;
	std::cout << "INSTRUCCIONES SOLO COMPILAR EL PROYECTO" << endl;
	std::cout << "COLOCAR LA TEXTURAS EN UNA CARPETA EN EL DISCO D" << endl;
	std::cout << "AL COMPILAR EL PROYECTO SE GENERARA UN CUBO EN EL CENTRO DE LA PANTALLA " << endl;
	std::cout << "TECLA Q: Movimiento R en sentido horario" << endl;
	std::cout << "TECLA W: Movimiento L en sentido horario" << endl;
	std::cout << "TECLA E: Movimiento U en sentido horario" << endl;
	std::cout << "TECLA R: Movimiento D en sentido horario" << endl;
	std::cout << "TECLA T: Movimiento F en sentido horario" << endl;
	std::cout << "TECLA Y: Movimiento B en sentido horario" << endl;
	std::cout << "TECLA Z: Resolvera el cubo que se transformo con los movimientos" << endl;
	std::cout << "	clasicos del Cubo de Rubik" << endl;
	std::cout << "Tecla X: Desordenara aleatoriamente el cubo de Rubik" << endl;
	std::cout << "Tecla C: Resolvera el cubo de Rubik desordenado aleatoriamente " << endl;
	std::cout << "	al presionar la tecla X" << endl;
	std::cout << "Tecla SPACE: Realizara la Animacion de la respiracion del " << endl;
	std::cout << "	cubo de Rubik" << endl;
	std::cout << "Tecla N: Realizara la Animacion de Expandir el Cubo" << endl;
	std::cout << "Tecla M: Realizara la Animacion de Contraer el Cubo" << endl;
	std::cout << "Tecla B: El cubo de Rubik cambiara de textura" << endl;
	std::cout << "//////////////////////////////////////////////////////" << endl;
	string route = argv[0];
	rutaImagen = "D://texturas//texturaFINAL.jpg";
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Proyecto Cubo de Rubik", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetScrollCallback(window, scroll_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);;
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	GLuint shaderProgram = glCreateProgram();

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	GLint linked;
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linked);
	if (linked) {
		glUseProgram(shaderProgram);
		std::cout << "Success\n";
	}
	else {
		std::cout << "Error\n";
	}

	glUseProgram(shaderProgram);

	projectionPos = glGetUniformLocation(shaderProgram, "projection");
	modelviewPos = glGetUniformLocation(shaderProgram, "view");
	viewPosPos = glGetUniformLocation(shaderProgram, "viewPos");
	modelview = glm::lookAt(cameraEye, cameraCenter, cameraUp);
	projection = glm::mat4(1.0f);
	framebuffer_size_callback(window, SCR_WIDTH, SCR_HEIGHT);
	glUniformMatrix4fv(projectionPos, 1, GL_FALSE, &projection[0][0]);
	glUniformMatrix4fv(modelviewPos, 1, GL_FALSE, &modelview[0][0]);
	glUniform3f(viewPosPos,cameraEye.x,cameraEye.y,cameraEye.z);
	///------------------------Textura------------------------///
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height, nrChannels;
	unsigned char *data = stbi_load(rutaImagen.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	///------------------------Cubo-Rubik------------------------///
	shader = shaderProgram;
	rubikCube = new Rubik(glm::vec3(centerX, centerY, centerZ), arista, offset, shader, texture);
	rubikCube->Generador();
	glEnable(GL_DEPTH_TEST);
	///------------------------Velocidad-----------------------///
	float time;
	glfwSetTime(0);
	float frameRate = 1.0f / 60.0f;

	while (!glfwWindowShouldClose(window))
	{
		time = glfwGetTime();
		glClearColor(0.25f, 0.25f, 0.25f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (time > frameRate) {
			rubikCube->Movimientos();
			glfwSetTime(0);
		}
		rubikCube->Dibujar();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
///------------------------Funciones------------------------///
void processInput(GLFWwindow* window)
{

}

void framebuffer_size_callback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	if (h > 0) {
		projection = glm::perspective(30.0f / 180.0f * glm::pi<float>(), (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);

		glUniformMatrix4fv(projectionPos, 1, GL_FALSE, &projection[0][0]);
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	glm::mat4 rotation = glm::mat4(1.0f);
	
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		rubikCube->setAnimacion("R");
		cuboga.push_back("R");
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		rubikCube->setAnimacion("L");
		cuboga.push_back("L");
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		rubikCube->setAnimacion("U");
		cuboga.push_back("U");
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		rubikCube->setAnimacion("D");
		cuboga.push_back("D");
	}
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
		rubikCube->setAnimacion("F");
		cuboga.push_back("F");
	}
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
		rubikCube->setAnimacion("B");
		cuboga.push_back("B");
	}
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) {
		if (cont < 13) {
			rubikCube->Expandir(0.1f);
			cont++;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
		if (cont > 1) {
			rubikCube->Expandir(-0.1f);
			cont--;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
		if (text) {
			rutaImagen = "D://texturas//uwu.png";
			text = false;
		}
		else {
			rutaImagen= "D://texturas//texturaFINAL.jpg";
			text = true;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
		std::vector<std::string> solution = get_solution(to_cube_not(cuboga));
		rubikCube->Solve(solution);
		cuboga = vector<string>();
	}
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
		std::vector<std::string> movements_to_scramble = scramble(15);
		for (int i = 0; i < (int)movements_to_scramble.size(); ++i)std::cout << movements_to_scramble[i] << 'f'; std::cout << std::endl;
		rubikCube->Desordenador(movements_to_scramble);
	}
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
		std::vector<std::string> solution = get_solution(to_cube_not(rubikCube->getSolucion()));
		rubikCube->Solve(solution);
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		rotation = glm::rotate(glm::mat4(1.0f), glm::pi<float>() / 12, glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		rotation = glm::rotate(glm::mat4(1.0f), -glm::pi<float>() / 12, glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		rotation = glm::rotate(glm::mat4(1.0f), -glm::pi<float>() / 12, glm::vec3(1.0f, 0.0f, 0.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		rotation = glm::rotate(glm::mat4(1.0f), glm::pi<float>() / 12, glm::vec3(1.0f, 0.0f, 0.0f));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		if (offset < 0.1) {
			offset = 0.2;
		}
		else { 
			offset = 0.05; 
		}
		rubikCube->setOffset(offset);
		rubikCube->Generador();
	}
	cameraEye = glm::mat3(rotation) * cameraEye;
	cameraUp = glm::mat3(rotation) * cameraUp;
	modelview = glm::lookAt(cameraEye, cameraCenter, cameraUp);
	glUniformMatrix4fv(modelviewPos, 1, GL_FALSE, &modelview[0][0]);
	glUniform3f(viewPosPos, cameraEye.x, cameraEye.y, cameraEye.z);
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	glm::vec3 direction = cameraCenter - cameraEye;
	GLfloat normal = sqrt(pow(direction.x, 2) + pow(direction.y, 2) + pow(direction.z, 2));
	direction.x /= normal * 3;
	direction.y /= normal * 3;
	direction.z /= normal * 3;
	if (yoffset > 0) {
		if (abs(cameraEye.x) > 0.5 || abs(cameraEye.y) > 0.5 || abs(cameraEye.z) > 0.5)
			cameraEye += direction;
	}
	else {
		if (abs(cameraEye.x) < 30.0 || abs(cameraEye.y) < 30.0 || abs(cameraEye.z) < 30.0)
			cameraEye -= direction;
	}
	modelview = glm::lookAt(cameraEye, cameraCenter, cameraUp);
	glUniformMatrix4fv(modelviewPos, 1, GL_FALSE, &modelview[0][0]);
}
