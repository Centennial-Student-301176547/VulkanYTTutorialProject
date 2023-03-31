#version 450

//declares the location 
//declares this value is an output with keyword 'out'
layout (location =0) in vec3 fragColor;

layout (location = 0) out vec4 outColor;

layout(push_constant) uniform Push {
	mat4 transform; //projection * view * model
	mat4 normalMatrix;
} push;

void main() {
	
	//will paint this color on a pixel by pixel basis
	outColor = vec4(fragColor, 1.0);
}