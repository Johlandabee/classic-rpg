#pragma once
#include "Dictionary.h"

using namespace std;
using namespace common;

class Config {
	Dictionary<string, string>* props = nullptr;
	string fileName;

	void loadFile() const;

public:
	explicit Config(string fileName);
	Config();
	~Config();

	string getStringValue(string const& key, string defaultValue = "") const;
	int getIntValue(string const& key, int defaultValue) const;
	double getDoubleValue(string const& key, double defaultValue) const;
	bool getBooleanValue(string const& key, bool defaultValue) const;
};
