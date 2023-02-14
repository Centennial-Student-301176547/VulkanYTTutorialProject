#pragma once
#include "lve_window.hpp"
#include "lve_pipeline.hpp"


//application that opens a window

namespace lve {
	class FirstApp {

	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		LveWindow lveWindow{ WIDTH, HEIGHT, "Vulkan YT Project" };
		//ensure we are passing in the binary spv file
		LvePipeline lvePipeline{ "simple_shader.vert.spv", "simple_shader.frag.spv" };
	};
}