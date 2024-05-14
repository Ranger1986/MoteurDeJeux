// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow *window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <algorithm>

using namespace glm;

#include <common/shader.hpp>
#include <common/objloader.hpp>
#include <common/texture.hpp>
#include <common/vboindexer.hpp>

#include "src/helper.cpp"

#include "src/Mesh.hpp"
#include "src/Transform.hpp"
#include "src/Quad.hpp"
#include "src/Scene.hpp"
#include "src/Node.hpp"
#include "src/Obstacle.hpp"
#include "src/Ennemy.hpp"

#include "src/mapreader.hpp"
#include "src/RessourceLoader.hpp"

void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
glm::vec3 camera_position = glm::vec3(0.0f, 0.0f, 20.0f);
glm::vec3 camera_target = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);

// timing
float deltaTime = 0.0f; // time between current frame and last frame
float lastFrame = 0.0f;

// rotation
float angle = 0.;
float angle_coef = 1.;
float zoom = 1.;
/*******************************************************************************/

mat4 modelMatrix;
mat4 viewMatrix;
mat4 projectionMatrix;

Player *player;

int main(void)
{
    // Initialise GLFW
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow(1024, 768, "2BROS", NULL, NULL);
    if (window == NULL)
    {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    // Hide the mouse and enable unlimited mouvement
    //  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set the mouse at the center of the screen
    glfwPollEvents();
    glfwSetCursorPos(window, 1024 / 2, 768 / 2);

    // Dark blue background
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Cull triangles which normal is not towards the camera
    // glEnable(GL_CULL_FACE);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create and compile our GLSL program from the shaders
    GLuint programID = LoadShaders("vertex_shader.glsl", "fragment_shader.glsl");

    GLuint Vlocation = glGetUniformLocation(programID, "V");
    GLuint Plocation = glGetUniformLocation(programID, "P");
    GLuint Mlocation = glGetUniformLocation(programID, "M");

    GLuint dirt_texture = loadTexture2DFromFilePath("Texture/dirt_text.png");
    GLuint stone_texture = loadTexture2DFromFilePath("Texture/stone_text.png");
    GLuint steve_texture = loadTexture2DFromFilePath("Texture/steve.jpg");
    GLuint red_texture = loadTexture2DFromFilePath("Texture/red.png");
    GLuint yellow_texture = loadTexture2DFromFilePath("Texture/yellow.png");

    Scene * scene= new Scene(Mlocation);
    Quad square = Quad(vec3(0, 0, 0), 1);
    init();
    player = getPlayerByID(0);
    player->transform.translate(vec3(0, 2, 0));
    player->parent=scene;
    player->bullet->parent=scene;

    // player = Load();
    // player->parent=scene;
    // player->hitbox = new HitboxRectangle(vec3(-0.5, -0.5, 0), vec3(0.5, 0.5, 0));
    // player->mesh = square.generateMesh(steve_texture);
    // player->transform.translate(vec3(0, 2, 0));
    // player->transform.scale(0.5);
    // player->fireDelay=1;
    // player->direction=1;
    // player->HP=3;
    
    Ennemy * ennemy = new Ennemy();
    ennemy->parent=scene;
    ennemy->hitbox = new HitboxRectangle(vec3(-0.5, -0.5, 0), vec3(0.5, 0.5, 0));
    ennemy->mesh = square.generateMesh(red_texture);
    ennemy->transform.translate(vec3(5, 5, 0));
    ennemy->transform.scale(0.75);
    ennemy->fireDelay=2;
    ennemy->direction=-1;
    ennemy->HP=3;

    RondeBehaviour * ronde = new RondeBehaviour();
    ronde->vision = new HitboxRectangle(vec3(-4, -0.5, 0), vec3(0, 0.5, 0));
    ennemy->behaviour=ronde;
    ennemy->behaviour->ennemy=ennemy;

    Bullet * newB = new Bullet();
    newB->TTL = 2;
    newB->parent=scene;
    newB->hitbox = new HitboxRectangle(vec3(-0.5, -0.5, 0), vec3(0.5, 0.5, 0));
    newB->mesh = square.generateMesh(yellow_texture);
    newB->transform.scale(0.25);
    ennemy->bullet= newB;

    scene->players.push_back(player);
    scene->ennemies.push_back(ennemy);

    vector<vector<string>> map = readmap("map2.txt");
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            std::cout << i << j << std::endl;
            std::cout << map[i][j] << std::endl;
            if (map[i][j][0]!='_')
            {
                if (map[i][j][0]=='O')
                {
                    std::cout << i << j << std::endl;
                    std::cout << map[i][j] << std::endl;
                    map[i][j].erase(0,1);
                    std::cout << i << j << std::endl;
                    std::cout << map[i][j] << std::endl;
                    Obstacle * newObstacle = new Obstacle(* getObstacleByID(stoi(map[i][j])));
                    newObstacle->transform.translate(vec3(i, j, 0));
                    newObstacle->parent=scene;
                    scene->obstacles.push_back(newObstacle);
                }
                else if (map[i][j][0]=='P')
                {
                    continue;
                }
                else if (map[i][j][0]=='E')
                {
                    continue;
                }
                 
            }
        }
    }
    scene->init();

    do
    {

        // Measure speed
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use our shader
        glUseProgram(programID);

        viewMatrix = lookAt(camera_position, camera_target, camera_up);
        projectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

        glUniformMatrix4fv(Vlocation, 1, GL_FALSE, &viewMatrix[0][0]);
        glUniformMatrix4fv(Plocation, 1, GL_FALSE, &projectionMatrix[0][0]);
        scene->applyPhysics(deltaTime);
        scene->draw();
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0);

    // Cleanup VBO and shader
    scene->deleteBuffers();
    glDeleteProgram(programID);
    glDeleteVertexArrays(1, &VertexArrayID);
    glDeleteTextures(1, &dirt_texture);
    glDeleteTextures(1, &stone_texture);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // Camera zoom in and out
    float cameraSpeed = 2.5 * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera_position += cameraSpeed * camera_target;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera_position -= cameraSpeed * camera_target;
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // TODO add translations
    // vec3 deplacement = vec3(0,0,0);
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        {player->tir();}
    int vitesseDeplacement = 2;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        player->jump();
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        player->vitesse.y-=10*deltaTime;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        player->vitesse.x=vitesseDeplacement;
        player->direction = +1;
    }
    else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        player->vitesse.x=-vitesseDeplacement;
        player->direction = -1;
    }
    else
        player->vitesse.x=0; //a trouver un meilleur moyen de gerer la fin de deplacement du joueur
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        player->parent->ennemies[0]->behaviour->update();
    }
    
    camera_target = player->transform.getTranslation();
    camera_position = vec3(camera_target.x, camera_target.y, camera_position.z);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
