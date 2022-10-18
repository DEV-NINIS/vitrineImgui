#include <iostream>
#include <Windows.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui/imgui_bezier_math.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "InitialiseWindow.h"

#define EDITOR_WINDOW_SIZE ImVec2((glfwGetVideoMode(glfwGetPrimaryMonitor())->height) / 1.5, (glfwGetVideoMode(glfwGetPrimaryMonitor())->width) / 4.5)
#define EDITOR_WINDOW_SIZE_X (glfwGetVideoMode(glfwGetPrimaryMonitor())->height) / 1.5
#define EDITOR_WINDOW_SIZE_Y (glfwGetVideoMode(glfwGetPrimaryMonitor())->width) / 4.5




int main(int agrv, char* argv[]) {

	// set parametters of OpenGL
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4.6);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4.6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef _APPLE_
	glfwwindowhint(GLFW_ OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // _APPLE_
	 int* lastX; lastX = new int; *lastX = (glfwGetVideoMode(glfwGetPrimaryMonitor())->width) / 2.0f;
	 int* lastY; lastY = new int; *lastY = (glfwGetVideoMode(glfwGetPrimaryMonitor())->height) / 2.0f;
	//
	int* resY = new int; *resY = 1440; float resX2 = 2560;
	int* resX = new int; *resX = 2560; float resY2 = 1440;
	GLFWmonitor* MyMonitor = glfwGetPrimaryMonitor(); // The primary monitor.. Later Occulus?..

	const GLFWvidmode* mode = glfwGetVideoMode(MyMonitor);
	*resX = mode->width;
	*resY = mode->height;
#ifdef HOT_REALOAD
	std::vector<GLFWwindow*> window; window.push_back(glfwCreateWindow(glfwGetVideoMode(glfwGetPrimaryMonitor())->width,
		glfwGetVideoMode(glfwGetPrimaryMonitor())->height, "DevNinisEngineMotion",
		nullptr, nullptr));
#endif // HOT_REALOAD
#ifndef HOT_REALOAD
	GLFWwindow* window;
	window = glfwCreateWindow(glfwGetVideoMode(glfwGetPrimaryMonitor())->width,
		glfwGetVideoMode(glfwGetPrimaryMonitor())->height, "Example_Interface",
		nullptr, nullptr);
#endif

	if (window == NULL) {
		MessageBoxA(0, static_cast<const char*>("failed to initialise glad"), "ERROR", 0);
		exit(EXIT_FAILURE);
		return -1;
	}
	glfwMakeContextCurrent(window);
	// set glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		MessageBoxA(0, static_cast<const char*>("failed to initialise glad"), "ERROR", 0);
		exit(EXIT_FAILURE);
		return -1;
	}
	// 

	else {

		glViewport(*resX / 4.25, *resY / 4.25, *resX, *resY);

	}

#define SRC_WIDTH = glfwGetVideoMode(glfwGetPrimaryMonitor())->width / 2.0f;
#define SRC_HEIGHT = glfwGetVideoMode(glfwGetPrimaryMonitor())->height / 2.0f;
	InitialiseWindow windowGui(window);
	
	while (!glfwWindowShouldClose(window)) {
		glfwGetFramebufferSize(window, lastX,  lastY);
		glViewport(0, 0, *lastX, *lastY);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.6, 0.9, 0.9, 0.9);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		windowGui.initialiseSettingsWindow(window);

		ImGui::Begin("test", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

		ImGui::Button("add", ImVec2(EDITOR_WINDOW_SIZE_X / 5, EDITOR_WINDOW_SIZE_Y / 10));
		ImGui::End();
		windowGui.EndFrame();
		glEnable(GL_DEPTH_TEST);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}