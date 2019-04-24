#version 330 core

uniform sampler2D texture1;

in vec2 TexCoords;

out vec4 fragColor;




void main(void)
{
      vec4 color=texture(texture1,TexCoords);
	  if(TexCoords.x>=0.5)
	  {
	       float grey=color.r*0.299+color.g*0.587+color.b*0.114;
		   fragColor =vec4(grey,grey,grey,1.0);
	  }
	  else{
	   fragColor =color;

	  }
}