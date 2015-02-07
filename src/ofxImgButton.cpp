#include "ofxImgButton.h"

ofxImgButton::ofxImgButton(){
}

ofxImgButton::~ofxImgButton(){
	//
}

void ofxImgButton::setup(string imageName, float width, float height){
	buttonImg.loadImage(imageName);
	button.x = 0;
	button.y = 0;
	button.width =  (width > 0) ? width : buttonImg.getWidth();
	button.height = (height > 0) ? height : buttonImg.getHeight();
	value = false;
	isToggle = false;

	ofRegisterMouseEvents(this, OF_EVENT_ORDER_BEFORE_APP);

}

void ofxImgButton::setup(string imgName, string imgToggleName, float width, float height){
	buttonImg.loadImage(imgName);
	buttonImgToggle.loadImage(imgToggleName);

	button.x = 0;
	button.y = 0;
	button.width = (width > 0) ? width : buttonImg.getWidth();
	button.height = (height > 0) ? height : buttonImg.getHeight();
	value = false;
	isToggle = true;

	

	ofRegisterMouseEvents(this, OF_EVENT_ORDER_BEFORE_APP);

}

void ofxImgButton::draw(int x, int y, int w, int h){
	button.x != x ? button.x = x : 0;
	button.y != y ? button.y = y : 0;
	button.width != w ? button.width = w : 0;
	button.height != h ? button.height = h : 0;
	draw();
}
void ofxImgButton::draw(int x, int y){
	button.x != x ? button.x = x : 0;
	button.y != y ? button.y = y : 0;
	draw();
}
void ofxImgButton::draw(ofPoint p){
	button.x != p.x ? button.x = p.x : 0;
	button.y != p.y ? button.y = p.y : 0;
	draw();
}
void ofxImgButton::draw(){
	if (isToggle){
		if (!value){
			buttonImg.draw(button.x, button.y, button.width, button.height);
		}
		else {
			buttonImgToggle.draw(button.x, button.y, button.width, button.height);
		}
		
	}
	else {
		buttonImg.draw(button.x, button.y, button.width, button.height);
	}
}
void ofxImgButton::setImage(string imageName){
	buttonImg.loadImage(imageName);
}
void ofxImgButton::setToggleImage(string imageName){
	buttonImgToggle.loadImage(imageName);
}

void ofxImgButton::setWidth(int w){
	button.width = w;
}
void ofxImgButton::setHeight(int h){
	button.height = h;
}
float ofxImgButton::getWidth(){
	return button.width;
}
float ofxImgButton::getHeight(){
	return button.height;
}
void ofxImgButton::setWidthPercent(float w){
	button.width *= w;
}
void ofxImgButton::setHeightPercent(float h){
	button.height *= h;
}

void  ofxImgButton::setPosition(int x, int y){
	button.x = x;
	button.y = y;
}
void  ofxImgButton::setPosition(ofPoint p){
	button.x = p.x;
	button.y = p.y;
}

void ofxImgButton::setToggle(bool state){
	value = state;
}

/*
*****************************************************
				Mouse Funcitons
*****************************************************
*/

void ofxImgButton::mouseReleased(ofMouseEventArgs & args){
	if (button.inside(args.x, args.y)){
		value = !value;
		ofNotifyEvent(buttonEvent, value, this);
	}
}

void ofxImgButton::mouseMoved(ofMouseEventArgs & args){
	//
}

void ofxImgButton::mousePressed(ofMouseEventArgs & args){
	//
}

void ofxImgButton::mouseDragged(ofMouseEventArgs & args){
	//
}
