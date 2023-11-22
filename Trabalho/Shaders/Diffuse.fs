#version 460


in vec3 colorOut;
in vec3 Normal;
in vec3 crntPos;

uniform vec4 lightColor; 
uniform vec3 lightPos;

out vec4 fragColor;

void main()
{   

	// diffuse lighting
	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(lightPos - crntPos);
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	// only uses the ambient and diffuse coeficient
	fragColor =  vec4(colorOut,1.0f) * lightColor * ( diffuse)  ;
}