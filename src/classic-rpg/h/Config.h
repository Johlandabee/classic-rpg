#pragma once
#include <string>

using namespace std;

class Config {
public:
	Config(string fileName);
	~Config();

	string getStringValue(string key, string defaultValue = "");
	int getIntValue(string key, int defaultValue = 0);
	double getDoubleValue(string key, double defaultValue = 0.0);
	bool getBooleanValue(string key, bool defaultValue = false);

private:
	string fileName_;
	void loadFile();
};

