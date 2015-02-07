#pragma once

#include "ofParameter.h"
#include "ofMain.h"

enum ColorPickerType {
	RADIAL =	1,
	RADIAL_BRIGHTNESS = 2,
	HORIZONTAL =	3,
	HORIZONTAL_BRIGHTNESS = 4,
	HORIZONTAL_HALF = 5,
	HORIZONTAL_HALF_BRIGHTNESS = 6,
	VERTICAL = 7,
	VERTICAL_BRIGHTNESS = 8,
	VERTICAL_HALF = 9,
	VERTICAL_HALF_BRIGHTNESS = 10
};

class ofxColorPicker{
	
public:
	ofxColorPicker();
	~ofxColorPicker();
	void setup(ColorPickerType type, float width = 90, float height = 90);
	void draw(int x, int y, int w, int h);
	void draw(int x, int y);
	void draw(ofPoint p);
	void draw();
	void setWidth(int w);
	void setHeight(int h);
	float getWidth();
	float getHeight();
	void setPosition(int x, int y);
	void setPosition(ofPoint p);

	ColorPickerType pickerType;
	ofRectangle pickerRect;
	ofImage		colorPicker;

	void mouseReleased(ofMouseEventArgs & args);
	void mouseMoved(ofMouseEventArgs & args);
	void mousePressed(ofMouseEventArgs & args);
	void mouseDragged(ofMouseEventArgs & args);

	ofEvent<const ofColor> pickerEvent;

};
