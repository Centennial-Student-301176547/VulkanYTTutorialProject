#pragma once

#include "lve_camera.hpp"
#include "lve_device.hpp"
#include "lve_game_object.hpp"
#include "lve_pipeline.hpp"
#include "lve_frame_info.hpp"



//std
#include <memory>
#include <vector>


//application that opens a window

namespace lve {
	class SimpleRenderSystem {

	public:	

		SimpleRenderSystem(LveDevice& device, VkRenderPass renderPass);
		~SimpleRenderSystem();

		SimpleRenderSystem(const SimpleRenderSystem&) = delete;
		SimpleRenderSystem& operator=(const SimpleRenderSystem&) = delete;

		void renderGameObjects(FrameInfo &frameInfo, std::vector<LveGameObject> &gameObjects);


	private:
		void createPipelineLayout();
		void createPipeline(VkRenderPass renderPass);
		

		LveDevice &lveDevice;

		std::unique_ptr<LvePipeline> lvePipelinePtr;
		VkPipelineLayout pipelineLayout;
	};
}