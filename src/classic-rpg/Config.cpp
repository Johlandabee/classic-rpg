#include "lib/Config.h"

Config::Config(string fileName){
	fileName_ = fileName;
}

Config::~Config(){

}

string Config::getStringValue(string key, string defaultValue){
	// ToDo

	return "";
}

int Config::getIntValue(string key, int defaultValue){
	// ToDo

	return 0;
}

double Config::getDoubleValue(string key, double defaultValue){
	// ToDo

	return 0.;
}

bool Config::getBooleanValue(string key, bool defaultValue){
	// ToDo
	return false;
}

void loadFile(){
	
}