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
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); //resize will be handled using a special function

		windowPtr = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(windowPtr, this);
		glfwSetFramebufferSizeCallback(windowPtr, framebufferResizeCallback);
	}

	bool LveWindow::shouldClose() {

		return glfwWindowShouldClose(windowPtr);
	}

	VkExtent2D LveWindow::getExtent() {
		return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) };
	}

	void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surfacePtr) {
		if (glfwCreateWindowSurface(instance, windowPtr, nullptr, surfacePtr) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface");
		}
	}

	void LveWindow::framebufferResizeCallback(GLFWwindow *window, int width, int height) {
		auto lveWindow = reinterpret_cast<LveWindow*>(glfwGetWindowUserPointer(window));
		lveWindow->framebufferResized = true;
		lveWindow->width = width;
		lveWindow->height = height;

	}

	

}

