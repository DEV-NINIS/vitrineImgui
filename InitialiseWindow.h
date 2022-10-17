#pragma once
#ifndef INITIALISEWINDOW
#define INITIALISEWINDOW

#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>

class InitialiseWindow
{
public:
	InitialiseWindow(GLFWwindow* window);
	virtual ~InitialiseWindow();
	void EndFrame();
	void initialiseStyleWindow(GLFWwindow* window);
	void initialiseSettingsWindow(GLFWwindow* window);
private:
	
};

#endif // !InitialiseWindow

