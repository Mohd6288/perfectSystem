#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
    ofBackground(0);

	// Set default value for the flag to draw lines between particles
		bDrawLines = false;

	// Set initial values for the particle emitter
	emitterPos.set(ofGetWidth() * 0.5, ofGetHeight() * 0.5); // Center of the screen
	emitterVel.set(2, 0); // Emit particles to the right

	emitterRate = 1; // Number of particles to emit per frame
	emitterLifespan = 3.0; // How long each particle lives for
	emitterMass = 1.0; // How massive each particle is
	emitterAge = 20;

	// Setup GUI parameters
	gui.setup();
	gui.add(overallSpeed.setup("#Speed", 1, 0, 30));
	gui.add(noiseScale.setup("#NoiseScale", 0.01, 0, 0.1));
	gui.add(trail.setup("#Trail", 6, 0, 20));
	gui.add(maxLineDistance.setup("LineDistance", 20, 10, 100));
	gui.add(lineThickness.setup("Thickness", 1.0, 0.1, 30));
	gui.add(numPoint.setup("Point", 10, 100, 200));
	gui.add(sizeDot.setup("Dot Size", 1, 1, 20));

	// Create color picker
	gui.add(redCol.setup("Red Color", 1, 1, 255));
	gui.add(greenCol.setup("Green Color", 1, 1, 255));
	gui.add(blueCol.setup("Blue Color", 1, 1, 255));

    //a variable used to manage the state of the program
    currentKey = '1';

	// Disable automatic background clearing
}

//--------------------------------------------------------------
void ofApp::update() {
    ParticleSys.update(mouseX, mouseY, currentKey, redCol, greenCol, blueCol,sizeDot);//update the Particle system
	ofSetBackgroundAuto(bDrawLines);

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSetColor(0, 0, 0, trail);
    ParticleSys.draw();//draw the Particle system


	// Draw GUI controls
	ofSetHexColor(0xf00ff); // Set color for GUI controls
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    ParticleSys.addParticle(x, y);//add Particles to our system
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    currentKey = key;//read the classes to figure out what key affects behaviour
	bDrawLines = !bDrawLines;

}
