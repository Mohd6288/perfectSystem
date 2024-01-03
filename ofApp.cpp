#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(45);
    ofBackground(0);

	// Set default value for the flag to draw lines between particles
		bDrawLines = true;
    //load sound sample
        sound1.load("music.mp3");


	// Setup GUI parameters
	gui.setup();
	
	gui.add(trail.setup("#Trail", 6, 0, 20));
	gui.add(sizeDot.setup("Dot Size", 1, 1, 20));

	// Create color picker
	gui.add(redCol.setup("Red Color", 100, 1, 255));
	gui.add(greenCol.setup("Green Color", 150, 1, 255));
	gui.add(blueCol.setup("Blue Color", 190, 1, 255));

    //a variable used to manage the state of the program
    currentKey = '1';

	

	// Set font and size for the text
	font.load("myFont.ttf", 10);
    // Explanatory text
	explanationText = "";
}

void ofApp::update() {
    ParticleSys.update(mouseX, mouseY, currentKey, redCol, greenCol, blueCol, sizeDot);

    // Update the explanation text based on color conditions
    float maxColor = 0;
    float minColor = 255;

    if (redCol > greenCol && redCol > blueCol) {
        maxColor = redCol;
    }
    else if (greenCol > redCol && greenCol > blueCol) {
        maxColor = greenCol;
    }
    else {
        maxColor = blueCol;
        explanationText = "Press 1,2,3 and L with mouse";
    }

    if (redCol < greenCol && redCol < blueCol) {
        minColor = redCol;
    }
    else if (greenCol < redCol && greenCol < blueCol) {
        minColor = greenCol;
    }
    else {
        minColor = blueCol;
        explanationText = "Press 1,2,3 and L with mouse";
    }

    float midColor = redCol + greenCol + blueCol - maxColor - minColor;

    if (maxColor == redCol) {
        if (greenCol < blueCol) {
            explanationText = "Magenta-Like Color (Harmonic Colors)";
        }
        else {
            explanationText = "Red-Like Color (Harmonic Colors)";
        }
    }
    else if (maxColor == greenCol) {
        if (redCol < blueCol) {
            explanationText = "Cyan-Like Color (Harmonic Colors)";
        }
        else {
            explanationText = "Green-Like Color (Harmonic Colors)";
        }
    }
    else {
        if (redCol < greenCol) {
            explanationText = "Bluesh-Like Color (Harmonic Colors)";
        }
        else {
            explanationText = "Blue-Like Color (Harmonic Colors)";
        }
    }

    // Add additional conditions based on user interactions
    if (currentKey == '1') {
        // Gradual transition between harmonic colors logic
        // You can implement a smooth color transition over time here
        explanationText += "\nGradual Transition Between Harmonic Colors\n MoveAway Applied";
    }
    else if (currentKey == '2') {
        // Apply mouse attraction and repulsion logic
        explanationText += "\nMouse Attraction and Repulsion Applied\n Partricles Folow Mouse Appleid";
    }
    else if (currentKey == 'l') {
        // Press 'L' to toggle background clearing
        explanationText += "\nBackground Clearing Toggle: ON:OFF Press L";
    }
    else {
        explanationText = "Press ONE,TWO,THREE , L with mouse";

    }

    ofSetBackgroundAuto(bDrawLines);
}





//--------------------------------------------------------------
void ofApp::draw() {
    frameCount++;
    std::cout << frameCount << std::endl;
	ofSetColor(0, 0, 0, trail);

    if (frameCount > 0 && frameCount <= 5) {
        sound1.play();
    }
    else if (frameCount > 5 && frameCount <= 25) {
        for (int i = 0; i < 45; i++) {
            for (int j = 0; j < 30; j++) {
                font.drawString("HELLO!!!", 0 + (50 * j), 0 + (25 * i));
            }
        }
    }
    else if (frameCount >= 25 && frameCount <= 125) {
        font.drawString("WELCOME TO MY PARTICLE SYSTEM", ofGetWidth() / 2 - 125, ofGetHeight() / 2);
        font.drawString("TO SKIP INTRO PRESS SPACE BAR", ofGetWidth() / 2 - 125, 50);
    }
    else if (frameCount >= 125 && frameCount <= 225) {
        font.drawString("ARE YOU READY TO LEARN???", ofGetWidth() / 2 - 100, ofGetHeight() / 2);
        font.drawString("TO SKIP INTRO PRESS SPACE BAR", ofGetWidth() / 2 - 125, 50);
    }
    else if (frameCount >= 230 && frameCount <= 240) {
        for (int i = 0; i < 35; i++) {
            for (int j = 0; j < 35; j++) {
                ofSetColor(155, 50, 55);
                font.drawString(":(  :(  :(  :(  :(  :(", 0 + (185 * j), 0 + (25 * i));
            }
        }
    }
    else if (frameCount >= 240 && frameCount <= 330) {
        ofSetColor(100, 50, 50);
        font.drawString("IT SHOULD BE FUN I PROMISE", ofGetWidth() / 2 - 100, ofGetHeight() / 2);
    }
    else if (frameCount >= 330 && frameCount <= 445) {
        ofSetColor(100, 50, 50);
        font.drawString("FIRSTLY WHAT IS A PARTICLE SYSTEM??", ofGetWidth() / 2 - 125, ofGetHeight() / 2);
    }
    else if (frameCount >= 445 && frameCount <= 460) {
        for (int i = 0; i < 35; i++) {
            for (int j = 0; j < 30; j++) {
                ofSetColor(155, 50, 55);
                font.drawString("? ? ? ? ? ? ? ? ? ? ?", 0 + (175 * j), 0 + (25 * i));
            }
        }
    }
    else if (frameCount >= 460 && frameCount <= 1000) {
        ofSetColor(100, 50, 50);
        font.drawString("A PARTICLE SYSTEM IS A TECHNIQUE IN GAME PHYSICS,", ofGetWidth() / 2 - 225 + 25, ofGetHeight() / 2 - 100);
        font.drawString("MOTION GRAPHICS, AND COMPUTER GRAPHICS.", ofGetWidth() / 2 - 190 + 25, ofGetHeight() / 2 - 75);
        font.drawString("IT USES A LARGE NUMBER OF SMALL PARTICLES (SPRITES) OR", ofGetWidth() / 2 - 225, ofGetHeight() / 2 - 25);
        font.drawString("OTHER GRAPHIC OBJECTS TO SIMULATE CERTAIN TYPES OF 'FUZZY' PHENOMENA", ofGetWidth() / 2 - 285 + 25, ofGetHeight() / 2 - 0);
        font.drawString("FOR EXAMPLE - SMOKE, FIRE, STARS CAN ALL BE GENERATED BY USING A PARTICLE SYSTEM", ofGetWidth() / 2 - 335 + 25, ofGetHeight() / 2 + 50);
    }

    else if (frameCount >= 1000 && frameCount <= 1100) {
        ofSetColor(100, 50, 50);
        font.drawString("MY SYSTEM IS A SIMPLE PATTERN GENERATOR", ofGetWidth() / 2 - 150, ofGetHeight() / 2);
    }
    else if (frameCount >= 1100 && frameCount <= 1200) {
        ofSetColor(150, 500, 150);
        font.drawString("I'LL SHOW YOU!!!", ofGetWidth() / 2 - 75, ofGetHeight() / 2);
    }
    else if (frameCount >= 1200 && frameCount <= 1250) {
        for (int i = 0; i < 35; i++) {
            for (int j = 0; j < 30; j++) {
                ofSetColor(55, 100, 55);
                font.drawString("LETS START WITH ONE PARTICLE", 0 + (230 * j), 0 + (25 * i));
            }
        }
    }
    else if (frameCount >= 1250 && frameCount <= 1350) {
        ofSetColor(100, 0, 50);
        font.drawString("IN THIS PROJECT, COLOR THEORY IS INCORPORATED TO ENHANCE VISUAL APPEAL.", ofGetWidth() / 2 - 75, 200);
    }
    else if (frameCount >= 1400 && frameCount <= 1600) {
        ofSetColor(100, 0, 250);
        font.drawString("HARMONIC COLORS (RED, GREEN, BLUE) CREATE PLEASING INTERACTIONS'", ofGetWidth() / 2 - 85, 200);
        font.drawString("WHILE CUSTOM COLORS RESULT IN UNIQUE VISUAL EFFECTS.", ofGetWidth() / 2 - 65, 220);
    }
    else if (frameCount >= 1600 && frameCount <= 1800) {
        ofSetColor(100, 0, 50);
        font.drawString("EACH PARTICLE SPAWNS DEPENDING", ofGetWidth() / 2 - 115, 200);
        font.drawString("ON A SET OF PARAMETERS", ofGetWidth() / 2 - 90, 220);
    }
    else if (frameCount >= 1800 && frameCount <= 2000) {
        ofSetColor(100, 0, 50);
        font.drawString("AND EACH PARAMETERS MANIPULATES", ofGetWidth() / 2 - 125, 200);
        font.drawString("THE PARTICLE", ofGetWidth() / 2 - 55, 220);
    }
    else if (frameCount >= 2000 && frameCount <= 2150) {
        ofSetColor(100, 0, 50);
        font.drawString("how WE Can Interacte I HEAR YOU ASK??", ofGetWidth() / 2 - 150, 200);
    }
    else if (frameCount >= 2150 && frameCount <= 2550) {
        for (int i = 0; i < 35; i++) {
            ofSetColor(100, 50, 55);
            font.drawString("VELOCITY    ANGLE    Postion    ROTATE    FORCE    SPINNING    HISTORY    Colours    FRICTION", 140, 0 + (25 * i));
        }
    }
    else if (frameCount >= 2550 && frameCount <= 2700) {
        ofSetColor(100, 0, 250);
        font.drawString("EACH OF THESE PARAMETERS DETEMINE THE RULES FOR EACH OF THE NEXT BORN PARTICLE", ofGetWidth() / 2 - 275, 200);
    }
    else if (frameCount >= 2700 && frameCount <= 2825) {
        ofSetColor(100, 50, 50);
        font.drawString("NOW LETS SEE HOW THESE PARTICLES REACT WHEN THERE'S MORE THAN ONE", ofGetWidth() / 2 - 275, 200);
    }
    else if (frameCount >= 2825 && frameCount <= 3020) {
        ofSetColor(100, 50, 50);
        font.drawString("BUT!!!!!! I THINK THE BEST WAY OF LEARNING IS BY TEACHING YOURSELF", ofGetWidth() / 2 - 275, 200);
    }
    else if (frameCount >= 3020 && frameCount <= 3150) {
        ofSetColor(100, 0, 250);
        font.drawString("WOULDN'T YOU AGREE????", ofGetWidth() / 2 - 100, 200);
    }
    else if (frameCount >= 3150 && frameCount <= 3300) {
        ofSetColor(100, 50, 50);
        font.drawString("PRESS L To and 1 to see colour Effect", ofGetWidth() / 2 - 270, 200);
    }
    else if (frameCount >= 3300 && frameCount <= 3500) {
        ofSetColor(100, 50, 50);
        font.drawString("CLICK AND DRAG ON ANY PARAMETER YOU WANT", ofGetWidth() / 2 - 175, 200);
        font.drawString("EXPERIMENT WITH COLOR SELECTION AND INTERACTIONS TO OBSERVE THE EFFECTS.", ofGetWidth() / 2 - 200, 220);
    }
    else if (frameCount >= 3500 && frameCount <= 3550) {
        for (int i = 0; i < 35; i++) {
            for (int j = 0; j < 30; j++) {
                ofSetColor(120, 50, 55);
                font.drawString("ENJOY!!!", 0 + (50 * j), 0 + (25 * i));
            }
        }
    }
    //Drawing Interface at a certain time in the demonstration
    if (frameCount > 3150) {
        ParticleSys.draw();//draw the Particle system
        ofSetHexColor(0xf00ff); // Set color for GUI controls
        gui.draw();
        //Draw background rectangle
        ofSetColor(0);
        ofDrawRectangle(ofGetWidth() / 2, 0, font.stringWidth(explanationText) + 20, font.stringHeight(explanationText) + 20);
        ofSetColor(255);
        font.drawString(explanationText, ofGetWidth() / 2, 20);
    }
	

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    ParticleSys.addParticle(x, y);//add Particles to our system
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    currentKey = key;//read the classes to figure out what key affects behaviour
	if (key == 'l') {
	bDrawLines = !bDrawLines;
    }
    if (key == ' ') {
        frameCount = 3150;
        sound1.stop();
    }
}
