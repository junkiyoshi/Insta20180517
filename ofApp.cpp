#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(2);
	ofSetColor(239, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	int radius = 150;
	int half_len = 300;
	for (int deg = 0; deg < 360; deg += 2) {

		ofPoint circle_point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		float noise_value = ofNoise(circle_point.x * 0.015, circle_point.y * 0.015, ofGetFrameNum() * 0.005);
		ofPoint rect_point = make_rect_point(half_len * noise_value , deg);
		if (rect_point.length() > radius) {

			rect_point = make_rect_point(half_len, deg);
		}
		else {

			rect_point = ofPoint(rect_point.length() * cos(deg * DEG_TO_RAD), rect_point.length() * sin(deg * DEG_TO_RAD));
		}

		ofDrawLine(circle_point, rect_point);
	}
}

//--------------------------------------------------------------
ofPoint ofApp::make_rect_point(float len, int deg) {

	int param = (deg + 45) / 90;
	ofPoint point;

	switch (param % 4) {

	case 0:

		return ofPoint(len, ofMap((deg + 45) % 90, 0, 89, -len, len));
	case 1:

		return  ofPoint(ofMap((deg + 45) % 90, 0, 89, len, -len), len);
	case 2:

		return ofPoint(-len, ofMap((deg + 45) % 90, 0, 89, len, -len));
	case 3:

		return ofPoint(ofMap((deg + 45) % 90, 0, 89, -len, len), -len);
	default:

		return ofPoint(0, 0);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}