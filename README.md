ofxOneLineShader
======
ofxOneLineShader is an addon for openFrameworks.
Tested on openFrameworks ver. 0.8.4 with GLSL 1.2

## example
```cpp

ofxOneLineShader shader;
shader.loadFrangmentShader( "gl_FragColor = vec4( 0.0, 0.0, 0.0, color.r );" );

shader.begin();
// draw
shader.end();

```

## TODO
GLSL 1.5

## License
MIT License
