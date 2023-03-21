#pragma once

#define GLFW_INCLUDE_VULKAN //include vulkan headers along with glfw
#include <GLFW/glfw3.h>

//std
#include <string>

namespace lve {

	class LveWindow {

	public:
		LveWindow(int w, int h, std::string name);
		~LveWindow();

		//remove copy constructor to avoid dangling pointer
		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete;

		bool shouldClose();
		VkExtent2D getExtent();
		bool wasWindowResized() { return framebufferResized; }
		void resetWindowResizedFlag() { framebufferResized = false; }

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surfacePtr);

		GLFWwindow* getGLFWwindow() const { return windowPtr; }

	private:
		static void framebufferResizeCallback(GLFWwindow *window, int width, int height);
		void initWindow();

		int width;
		int height;
		bool framebufferResized = false;

		std::string windowName;
		GLFWwindow* windowPtr;
	};


}