#pragma once
#include <string>


class Config{
public:
	Config(string fileName);
	~Config();

	string getStringValue(string key);
	int getIntValue(string key);
	double getDoubleValue(string key);
	bool getBooleanValue(string key);

private:
	string fileName_;
	string keyValueStore_[][];
	void loadFile();
};
