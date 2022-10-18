#include "InitialiseWindow.h"
#include "imgui/imgui_bezier_math.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

#define EDITOR_WINDOW_POS ImVec2((glfwGetVideoMode(glfwGetPrimaryMonitor())->height) / 1.5, (glfwGetVideoMode(glfwGetPrimaryMonitor())->width) / 4.5)
#define EDITOR_WINDOW_SIZE ImVec2((glfwGetVideoMode(glfwGetPrimaryMonitor())->height) / 1.5, (glfwGetVideoMode(glfwGetPrimaryMonitor())->width) / 4.5)

// constructor , destructor
InitialiseWindow::InitialiseWindow(GLFWwindow* window) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	io.Fonts->AddFontFromFileTTF("resources/textFont/Heavitas.ttf", 10);
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 460");
	ImVec4* color = ImGui::GetStyle().Colors;
	color[ImGuiCol_WindowBg] = ImColor(53, 59, 91, 200);
	ImGuiStyle* style = &ImGui::GetStyle();
	io.IniFilename = nullptr;

	static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
	ImFontConfig icons_config;

	ImFontConfig CustomFont;
	CustomFont.FontDataOwnedByAtlas = false;


	icons_config.MergeMode = true;
	icons_config.PixelSnapH = true;
	icons_config.OversampleH = 2.5;
	icons_config.OversampleV = 2.5;


	// style window 

	style->WindowBorderSize = 0;
	style->WindowTitleAlign = ImVec2(0.5, 0.5);
	style->ButtonTextAlign = ImVec2(0.5, 0.5);
	style->FramePadding = ImVec2(1, 1);
	style->WindowMenuButtonPosition = ImGuiDir();
	style->Colors[ImGuiCol_TitleBg] = ImColor(53, 59, 91, 200);
	style->Colors[ImGuiCol_TitleBgActive] = ImColor(53, 59, 91, 200);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(53, 59, 91, 200);

	style->Colors[ImGuiCol_Button] = ImColor(222, 46, 82, 150);
	style->Colors[ImGuiCol_ButtonActive] = ImColor(255, 127, 163, 200);
	style->Colors[ImGuiCol_ButtonHovered] = ImColor(227, 24, 82, 150);

	style->Colors[ImGuiCol_Separator] = ImColor(53, 59, 91, 200);
	style->Colors[ImGuiCol_SeparatorActive] = ImColor(53, 59, 91, 200);
	style->Colors[ImGuiCol_SeparatorHovered] = ImColor(53, 59, 91, 200);

	style->Colors[ImGuiCol_MenuBarBg] = ImColor(53, 59, 91, 200);

	style->Colors[ImGuiCol_FrameBg] = ImColor(53, 59, 91, 200);
	style->Colors[ImGuiCol_FrameBgActive] = ImColor(53, 59, 91, 200);
	style->Colors[ImGuiCol_FrameBgHovered] = ImColor(53, 59, 91, 200);

	style->Colors[ImGuiCol_Header] = ImColor(0, 0, 0, 0);
	style->Colors[ImGuiCol_HeaderActive] = ImColor(0, 0, 0, 0);

	style->SelectableTextAlign = ImVec2(0.1, 0.1);
	style->PopupBorderSize = 0;
	style->FrameBorderSize = 0;
	style->ChildBorderSize = 0;
	style->TabBorderSize = 0;
	style->WindowBorderSize = 3;
	style->PopupRounding = 15;
	style->ChildRounding = 15;
	style->FrameRounding = 15;
	style->GrabRounding = 15;
	style->WindowRounding = 10;
	style->TabRounding = 15;
	style->MouseCursorScale = 50;
	style->IndentSpacing = 5;

	
}
InitialiseWindow::~InitialiseWindow() {

}
//
void InitialiseWindow::initialiseSettingsWindow(GLFWwindow* window) {
	ImGuiWindowFlags windowFlags = ImGuiWindowFlags_MenuBar;

	ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowSize(EDITOR_WINDOW_SIZE); 

	
}
void InitialiseWindow::initialiseStyleWindow(GLFWwindow* window) {
	
}
void InitialiseWindow::EndFrame() {
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}