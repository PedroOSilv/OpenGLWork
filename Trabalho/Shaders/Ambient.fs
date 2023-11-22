#version 460


in vec3 colorOut;
in vec3 Normal;
in vec3 crntPos;

uniform vec4 lightColor;

out vec4 fragColor;

void main()
{   
    // ambient lighting
	float ambient = 0.2f;

	// outputs final color
	// only uses the ambient coeficient
	fragColor =  vec4(colorOut,1.0f) * lightColor * ambient ;
}