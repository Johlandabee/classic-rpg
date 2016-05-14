#pragma once
#include "Dictionary.h"

using namespace std;
using namespace common;

class Config {
	Dictionary<string, string>* dictionary_ = nullptr;
	string fileName_;

	void loadFile() const;

public:
	explicit Config(string fileName);
	~Config();

	string getStringValue(string const& key, string defaultValue = "") const;
	int getIntValue(string const& key, int defaultValue) const;
	double getDoubleValue(string const& key, double defaultValue) const;
	bool getBooleanValue(string const& key, bool defaultValue) const;
};

