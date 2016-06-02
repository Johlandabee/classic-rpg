#include "Config.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
using namespace common;

Config::Config(string fileName) {
	this->fileName = fileName;
	this->props = new Dictionary<string, string>;
	loadFile();
}

Config::Config() {
}

Config::~Config() {
	delete props;
	props = nullptr;
}

string Config::getStringValue(string const& key, string defaultValue) const {
	if (props->containsKey(key)) {
		return props->operator[](key);;
	}

	return defaultValue;
}

int Config::getIntValue(string const& key, int defaultValue) const {
	if (props->containsKey(key)) {
		return atoi(props->operator[](key).c_str());;
	}

	return defaultValue;
}

double Config::getDoubleValue(string const& key, double defaultValue) const {
	if (props->containsKey(key)) {
		return atof(props->operator[](key).c_str());;
	}

	return defaultValue;
}

bool Config::getBooleanValue(string const& key, bool defaultValue) const {
	if (props->containsKey(key)) {
		auto value = props->operator[](key);
		transform(value.begin(), value.end(), value.begin(), tolower);
		istringstream iss(value);
		bool bValue;

		iss >> boolalpha >> bValue;

		return bValue;
	}

	return defaultValue;
}

void Config::loadFile() const {
	ifstream file(fileName);
	string line;

	const auto sepperator = '=';
	const auto comment = '#';

	if (file.good() && file.is_open()) {
		while (getline(file, line)) {
			if (line.find(sepperator) == -1 || line.find(comment) > -1) {
				continue;
			}

			string key, value;

			key = line.substr(0, line.find_first_of(sepperator));
			value = line.substr(line.find_first_of(sepperator) + 1, line.length() - 1);

			props->add(key, value);
		}
	}
	else {
		throw logic_error("Could not open config file");
	}
}