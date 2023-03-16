#version 450

//declares the location 
//declares this value is an output with keyword 'out'
layout (location = 0) out vec4 outColor;

layout(push_constant) uniform Push {
	vec2 offset;
	vec3 color;
} push;

void main() {
	
	//will paint this color on a pixel by pixel basis
	outColor = vec4(push.color, 1.0);
}