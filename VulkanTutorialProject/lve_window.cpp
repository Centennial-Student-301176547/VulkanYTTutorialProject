#include "lve_window.hpp"

//std
#include <stdexcept>

namespace lve {


	LveWindow::LveWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	LveWindow::~LveWindow() {
		glfwDestroyWindow(windowPtr);
		glfwTerminate();
	}

	void LveWindow::initWindow() {
		glfwInit(); //initalizes glfw library
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //tells glfw not to create an OpenGL context (we're using vulkan)
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //disables ability to resize the window after init, resize will be handled using a special function

		windowPtr = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

	bool LveWindow::shouldClose() {

		return glfwWindowShouldClose(windowPtr);
	}

	void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surfacePtr) {
		if (glfwCreateWindowSurface(instance, windowPtr, nullptr, surfacePtr) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface");
		}
	}

}