#version 460


in vec3 colorOut;
in vec3 Normal;
in vec3 crntPos;

uniform vec4 lightColor; 
uniform vec3 lightPos;
uniform vec3 camPos;

out vec4 fragColor;

void main()
{   
    // ambient lighting
	float ambient = 0.1f;

	// diffuse lighting
	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(lightPos - crntPos);
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	// specular lighting
	float specularLight = 50.0f;
	vec3  viewDirection = normalize(camPos - crntPos);
	vec3  reflectionDirection = reflect(-lightDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 30);
	float specular = specAmount * specularLight;

	// outputs final color
	fragColor =  vec4(colorOut,1.0f) * lightColor * ( specular)  ;
}