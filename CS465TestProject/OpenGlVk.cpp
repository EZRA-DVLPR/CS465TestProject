//#include <glad/glad.h>
//#include <glfw3.h>
//
////#include "pch.h"
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//
//// settings
//const unsigned int SCR_WIDTH = 1024;
//const unsigned int SCR_HEIGHT = 768;
//
//int main()
//{
//    // glfw: initialize and configure
//    // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
//#endif
//
//    // glfw window creation
//    // --------------------
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "CSC 465 - LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }    
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//        // -----
//        processInput(window);
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow *window)
//{
//    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		std::cout << "W Pressed" << std::endl;
//
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}
// 
////////////////////////////////////////////////////////////////
//
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"uniform vec3 triangleColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(triangleColor, 1.0);\n"
//"}\n\0";
//
//int main() {
//    // GLFW initialization
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "Color Animation", NULL, NULL);
//    if (window == NULL) {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//    // Load OpenGL function pointers
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // Create and compile vertex shader
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//    // Create and compile fragment shader
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    // Create shader program
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    // Delete shaders as they're linked into our program now and no longer necessary
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    // Set up vertex data and buffer(s)
//    float vertices[] = {
//        -0.5f, -0.5f, 0.0f, // bottom left
//         0.5f, -0.5f, 0.0f, // bottom right
//         0.0f,  0.5f, 0.0f  // top
//    };
//
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    // Set up color animation
//    float red = 0.0f;
//    float colorIncrement = 0.01f;
//
//    // Rendering loop
//    while (!glfwWindowShouldClose(window)) {
//        // Input
//        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//            glfwSetWindowShouldClose(window, true);
//
//        // Update color
//        red += colorIncrement;
//        if (red >= 1.0f || red <= 0.0f)
//            colorIncrement *= -1;
//
//        // Render
//        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        glUseProgram(shaderProgram);
//        int vertexColorLocation = glGetUniformLocation(shaderProgram, "triangleColor");
//        glUniform3f(vertexColorLocation, red, 0.0f, 0.0f);
//
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // Cleanup
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);
//
//    glfwTerminate();
//    return 0;
//}