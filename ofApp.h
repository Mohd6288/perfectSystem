#pragma once
#include "ofMain.h"
#include "ParticleSystem.h"
#include "ofxGui.h"

using namespace glm;

class ofApp : public ofBaseApp {

public:
	void setup() override;
	void update() override;
	void draw() override;
	void mouseDragged(int x, int y, int button) override;
	void keyPressed(int key) override;
	ParticleSystem ParticleSys{ 1000 };
	char currentKey;

	//color picker
	ofxFloatSlider blueCol;
	ofxFloatSlider redCol;
	ofxFloatSlider greenCol;

	ofxFloatSlider sizeDot;
	ofxFloatSlider trail;
	int frameCount = 0;      //This framecount gives the timer for my slide show
	ofSoundPlayer sound1;    //sound sample
private:

	ofxPanel gui;
	bool bDrawLines;

	// Explanatory text
	ofTrueTypeFont font;
	string explanationText;
};

