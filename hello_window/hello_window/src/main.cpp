/*****************************************************************//**
 * \file   Application.cpp
 * \brief  generate a window
 *
 * \author Flork
 * \date   March 2023
 *********************************************************************/

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // �汾��
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // �汾��
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // ����ģʽ

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // �½�һ��GLFW����
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    // ע��ص�����
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // ��ʼ��glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD!!" << std::endl;
        return -1;
    }


    // ��Ⱦѭ��
    while (!glfwWindowShouldClose(window))
    {
        // ��������
        processInput(window);

        // render
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // ����������
        glfwSwapBuffers(window);
        // ������޴����¼�
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}