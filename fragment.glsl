#version 330 core


struct Material {

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	sampler2D diffuseTex;
	


};

in vec3 outPos;
in vec3 outColor;
in vec3 outNormal;
in vec3 FragPos;


uniform vec3 cameraPos;


uniform Material material;



out vec4 FragColor;

uniform mat4 ModelMatrix;

uniform vec3 LightPos;

uniform vec3 ColorChange;


in vec2 TexCoord;

uniform sampler2D texture0;


void main()
{
	//AMBIENT_LIGHTNING
	vec3 ambientLight = material.ambient;

	 

	
	 vec3 norm = normalize(outNormal);
	//LightPosWorld = vec3(ModelMatrix * vec4(outPos, 1.0));
	/*vec3 lightDir = normalize(LightPos - outPos);
	float diffuse = clamp(dot(lightDir, norm),0,1);
	vec3 diffuseFinal = vec3(1.0f,1.0f,1.0f) * diffuse;*/


	// SPECULAR_LIGHTNING

	//
	
	 vec3 cameraPos = normalize(outPos - cameraPos);
	vec3 viewDir = normalize(cameraPos - outPos);
	vec3 reflectDir = reflect(-LightPos, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular =  1 * spec * material.specular;





	/*vec3 pointToLightDirVector = normalize(outPos - LightPosition);
	vec3 diffuseColor = vec3(1.f,0.f,0.f);
	float diffuse = clamp(dot(pointToLightDirVector,outNormal),0,1);
    vec3 diffuseFinal = diffuse * outColor ;*/




	//FragColor = vec4(outColor, 1.0f) * vec4(diffuseFinal, 1.0f);


	FragColor = vec4(ColorChange, 1.0f) * texture(material.diffuseTex, TexCoord) * vec4(ambientLight, 1.0f) * vec4(specular, 1.0f);

}