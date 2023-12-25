#include "ParticleSystem.h"

//-------------------------------------------------------
//use the constructor to create an initial number of Particles
ParticleSystem::ParticleSystem(int _numOfParticles)
{
    numOfParticles = _numOfParticles;
    

    for (int i = 0; i < numOfParticles / 4; i++) {
        vec2 loc = vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        vec2 vel = vec2(1 + ofRandom(-3, 3), 1 + ofRandom(-3, 3));
        float rad = ofRandom(2, 10);
        ofColor c = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
        float speedLimit = ofRandom(1, rad * 2);
        float speed = ofRandom(0.5, 1);

        //Particle a{loc, vel, rad, c, speedLimit, speed};
        Particle* a = new Particle{ loc, vel, rad, c, speedLimit, speed };
        Particles.push_back(a);
    }


}

ParticleSystem::~ParticleSystem()
{
    std::cout << "destroying all the Particles " << std::endl;
    for (Particle* a : Particles) {
        delete a; // give the memory back!
    }
}


//--------------------------------------------------------------
//call the update method on our Particles
void ParticleSystem::update(float msX, float msY, char key ,float r,float g, float b,float size) {

    for (int i = 0; i < Particles.size(); i++) {

        Particles[i]->update(msX, msY, key, r, g, b, size);

    }
}

//--------------------------------------------------------------
//call the draw methods on our Particles
void ParticleSystem::draw() {

    for (int i = 0; i < Particles.size(); i++) {
        Particles[i]->draw();
        //Particles[i].drawDebugSphere();//uncomment to see "collision" sphere

    }
}

//--------------------------------------------------------------
//Use this method to add another Particle object to our Particles vector
void ParticleSystem::addParticle(int x, int y) {
    vec2 loc = vec2(x, y);
    vec2 vel = vec2(1 + ofRandom(-3, 3), 1 + ofRandom(-3, 3));
    float rad = ofRandom(2, 10);
    ofColor c = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    float speedLimit = ofRandom(1, rad * 2);
    float speed = ofRandom(0.5, 1);


    //Particle a{loc, vel, rad, c, speedLimit, speed};
    Particle* a = new Particle{ loc, vel, rad, c, speedLimit, speed };

    Particles.push_back(a);

}

