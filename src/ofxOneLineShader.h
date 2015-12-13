//
//  ofxOneLineShader.h
//
//  Created by FUJIMOTO Naoaki on 14/10/14.
//  https://twitter.com/naokiring
//

#include "ofMain.h"

#ifndef _ofxOneLineShader_h_
#define _ofxOneLineShader_h_

class ofxOneLineShader
{
private:
	string mFragShaderPre;
	string mFragShaderMain;
	string mFragShaderPost;
	
	string mVertShaderPre;
	string mVertShaderMain;
	string mVertShaderPost;
	
	ofShader mShader;
	
	bool mVertexShaderLoaded;
	bool mFragmentShaderLoaded;
	bool mShaderProgramLinked;
	
	ofFbo mFbo;
	bool mUseFbo;
	
public:
	ofxOneLineShader()
	{
		mVertexShaderLoaded = false;
		mFragmentShaderLoaded = false;
		mShaderProgramLinked = false;
		
		setupFixedShader();
		
		loadVertexShader();
		loadFragmentShader();
		
	}
	~ofxOneLineShader()
	{
		
	}
	
public:
	
	void loadVertexShader( string vertShaderText = string( "gl_Position = ftransform();" ) )
	{
		mShaderProgramLinked = false;
		
		mVertShaderMain = vertShaderText + string( "\n" );
		
		string vertShader = mVertShaderPre + mVertShaderMain + mVertShaderPost;
		
		cout << vertShader << endl << endl;
		
		if ( mShader.setupShaderFromSource( GL_VERTEX_SHADER, vertShader ) )
		{
			mVertexShaderLoaded = true;
			linkProgram();
		}
		else
		{
			ofLogError( "ofxOneLineShader" ) << "loadVertexShader() failed.";
		}
		
	}
	
	void loadFragmentShader( string fragShaderText = string( "gl_FragColor = color;" ) )
	{
		mShaderProgramLinked = false;
		
		mFragShaderMain = fragShaderText + string( "\n" );
		
		string fragShader = mFragShaderPre + mFragShaderMain + mFragShaderPost;
		
		cout << fragShader << endl << endl;
		
		if ( mShader.setupShaderFromSource( GL_FRAGMENT_SHADER, fragShader ) )
		{
			mFragmentShaderLoaded = true;
			linkProgram();
		}
		else
		{
			ofLogError( "ofxOneLineShader" ) << "loadFragmentShader() failed.";
		}
		
	}
	
	void linkProgram()
    {
		if ( mVertexShaderLoaded && mFragmentShaderLoaded )
		{
			if ( mShader.linkProgram() )
			{
				mShaderProgramLinked = true;
			}
			else
			{
				ofLogError( "ofxOneLineShader" ) << "linkProgram failed.";
			}
			
		}
		
    }
	
	void begin()
	{
		if ( mShaderProgramLinked ) mShader.begin();
		
	}
	void end()
	{
		if ( mShaderProgramLinked ) mShader.end();
		
	}
	
private:
	void setupFixedShader();
	
};


#endif
