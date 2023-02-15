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

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surfacePtr);

	private:

		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* windowPtr;
	};


}