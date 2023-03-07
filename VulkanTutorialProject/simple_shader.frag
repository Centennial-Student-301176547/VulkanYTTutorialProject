#version 450

//declares the location 
//declares this value is an output with keyword 'out'
layout (location = 0) out vec4 outColor;

void main() {
	
	//will paint this color on a pixel by pixel basis
	outColor = vec4(1.0, 1.0, 0.0, 1.0);
}