//// My own Notes
//
//
////Must always include the following 2 lines of code:
////Always include glad BEFORE GLFW
//
//#include <glad/glad.h>
//#include <glfw3.h>
//
//#include <iostream>
//
////prototype explained later
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
////prototype for rendering
//void processInput(GLFWwindow* window);
//
//const unsigned int SCR_WIDTH = 1024;
//const unsigned int SCR_HEIGHT = 768;
//
////basic main function where we instantiate the GLFW window:
//int main() 
//{
//	//initialize GLFW
//	glfwInit();
//
//	/*
//		glfwWindowHint(GLFW_OPTION_TO_CONFIGURE, INTEGER)
//		where the integer represents the value of the option
//	*/
//	
//	/*
//		We want to change the OpenGL version to 3.3:
//		To this effect, we adjust the major (first number),
//		and the minor (the second number).
//
//		i.e. MAJOR.MINOR w/ 3.3 means MAJOR = 3, MINOR = 3.
//	*/
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//
//	//tells GLFW that we want to explicitly use the core-profile
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	/*
//		Now we're creating a window object:
//		glfwCreateWindow(WIDTH, HEIGHT, NAME_OF_WINDOW, ?, ?)
//	*/
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//
//	//if the window isn't created, terminate
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	//make the context of the window we just created the main context on the current thread
//	glfwMakeContextCurrent(window);
//
//	//want to call function on all resizes
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	/*
//		want to initialize GLAD before we call any opengl function
//		`glfwGetProcAddress` defines the correct function based on OS
//	*/
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		//std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	/*
//		now have to adjust the dimensions of the window
//		Note: OpenGL processes coordinates between -1 and 1
//		thus the range (-1, 1) gets mapoped to (0, 800) and (0, 600)
//	*/
//	glViewport(0, 0, 800, 600);
//
//	/*
//		should the user resize the window, we want to adjust the viewport as well
//		internally it just sets the height and width to values when resized
//		'void framebuffer_size_callback(GLFWwindow* window, int width, int height);'
//		as a result we have to tell GLFW to call the function on every window resize
//	*/
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	/*
//		keep the app open until the user closes the app
//
//		`glfwWindowShouldClose(WINDOW)` function checks at each loop iteration if the specified GLFW window has been told to close
//
//
//	*/
//	while(!glfwWindowShouldClose(window))
//	{
//
//		//input accepting for the window
//		processInput(window);
//
//		//insert rendering commands here
//
//		//set color buffer
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//		//clear bits in the color buffer
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		/*
//			swaps the color buffer(large buffer containing the color values per pixel in the window)
//			used for the current iteration and shows it as output to screen
//
//			most of the time, a single buffer will have images flicker. This is b/c the app draws top left to bottom right
//			which is generated step by step, possibly inducing error
//
//			to circumvent this issue, a double buffer is used:
//				a front buffer that contains the final output image at the screen
//				a back buffer that contains the rendering commands
//			typically, the rendering is done first so that the back buffer swaps with the front displaying the image instantly
//		*/
//		glfwSwapBuffers(window);
//
//		/*
//			checks if any events are trigger(keyboard / mouse)
//			also updates the window state and calls corresponding functions
//		*/
//		glfwPollEvents();
//	}
//
//	//terminate the program
//	glfwTerminate();
//	return 0;
//	
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}
//
//// process all input: query GLFW whether `q` or `ESC` keys are pressed react accordingly
//// all other inputs get handled here too
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//	//escape pressed => close window
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	//w pressed => log into console
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		std::cout << "W Pressed" << std::endl;
//
//}