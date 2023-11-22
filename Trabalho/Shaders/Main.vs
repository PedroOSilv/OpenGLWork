//Model Matrix  with Frequent Changes
#version 460

uniform mat4 projection;
uniform mat4 view;

in layout (location=0) vec3 vertexIn;
in layout (location=1) vec3 colorIn;
in layout (location=2) vec3 aNormal;
in layout (location=3) mat4 model;

out vec3 colorOut; 
out vec3 Normal;
out vec3 crntPos;

void main()
{
	crntPos = vec3 (model *vec4(vertexIn, 1.0f));
	
	gl_Position =  projection * view * vec4(crntPos, 1.0);
	colorOut = colorIn;

	Normal = mat3(transpose(inverse(model))) * aNormal;
}

