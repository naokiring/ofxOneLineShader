//
//  ofxOneLineShader.cpp
//
//  Created by FUJIMOTO Naoaki on 14/11/30.
//  https://twitter.com/naokiring
//

#include "ofxOneLineShader.h"


#define STRINGIFY(A) #A


	void ofxOneLineShader::setupFixedShader()
	{
		mVertShaderPre =
		string( "#version 120 \n" ) +
		STRINGIFY(
				  
varying vec3 position;

void main( void )
{
	position = vec3( gl_ModelViewMatrix * gl_Vertex );

	gl_TexCoord[0] = gl_MultiTexCoord0;

		);

		mVertShaderPost =
		STRINGIFY(

}

		);

		mFragShaderPre =
		string( "#version 120 \n" ) +
		STRINGIFY(
		
varying vec3 position;

uniform sampler2DRect tex0;

void main( void )
{
	vec2 texCoord = gl_TexCoord[0].st;
	vec4 color = texture2DRect( tex0, texCoord );
	
			);
			
			mFragShaderPost =
			STRINGIFY(
			
}
			
		);
		
	}

