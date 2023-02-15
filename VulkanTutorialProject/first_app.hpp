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
		LveDevice lveDevice{lveWindow};
		//ensure we are passing in the binary spv file
		LvePipeline lvePipeline{
			lveDevice,
			"simple_shader.vert.spv",
			"simple_shader.frag.spv",
			LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
	};
}