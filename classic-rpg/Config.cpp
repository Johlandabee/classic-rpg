#include "Config.h"

Config::Config(string fileName){
	fileName_ = fileName;
}

Config::~Config(){

}

string Config::getStringValue(string key){
	// ToDo

	return "";
}

int Config::getIntValue(string key){
	// ToDo

	return 0;
}

double Config::getDoubleValue(string key){
	// ToDo

	return 0.;
}

bool Config::getBooleanValue(string key){
	// ToDo
	return false;
}

void loadFile(){
	
}