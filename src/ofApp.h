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
	ParticleSystem ParticleSys{ 10 };
	char currentKey;

	//color picker
	ofxFloatSlider blueCol;
	ofxFloatSlider redCol;
	ofxFloatSlider greenCol;

	ofxFloatSlider sizeDot;
	ofxFloatSlider numPoint;
	ofxFloatSlider trail;
private:

	ofxPanel gui;
	ofxFloatSlider overallSpeed;
	ofxFloatSlider noiseScale;
	ofxFloatSlider maxLineDistance;
	ofxFloatSlider lineThickness;

	
	ofxToggle bLearnBackground;
	ofVec2f emitterPos;
	ofVec2f emitterVel;
	int emitterRate; // Number of particles to emit per frame
	float emitterLifespan; // How long each particle lives for
	float emitterMass; // How massive each particle is
	float emitterAge;
	bool bDrawLines;
};

