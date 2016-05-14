#include "h/Config.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
using namespace common;

Config::Config(string fileName) {
	fileName_ = fileName;
	dictionary_ = new Dictionary<string, string>;
	loadFile();
}

Config::~Config() {
	delete dictionary_;
	dictionary_ = nullptr;
}

string Config::getStringValue(string const& key, string defaultValue) const {
	if(dictionary_->containsKey(key)) {
		return dictionary_->operator[](key);;
	}

	return defaultValue;
}

int Config::getIntValue(string const& key, int defaultValue) const {
	if (dictionary_->containsKey(key)) {
		return atoi(dictionary_->operator[](key).c_str());;
	}

	return defaultValue;
}

double Config::getDoubleValue(string const& key, double defaultValue) const {
	if (dictionary_->containsKey(key)) {
		return atof(dictionary_->operator[](key).c_str());;
	}

	return defaultValue;
}

bool Config::getBooleanValue(string const& key, bool defaultValue) const {
	if (dictionary_->containsKey(key)) {
		auto value = dictionary_->operator[](key);
		transform(value.begin(), value.end(), value.begin(), ::tolower);
		istringstream iss(value);
		bool bValue;

		iss >> boolalpha >> bValue;

		return bValue;
	}

	return defaultValue;
}

void Config::loadFile() const {
	ifstream infile(fileName_);
	string line;

	const auto sepperator = '=';
	const auto comment = '#';

	if(infile.good() && infile.is_open()) {
		while(getline(infile, line)) {
			string key, value;
			
			if(line.find(sepperator) == -1 || line.find(comment) > -1) {
				continue;
			}

			key = line.substr(0, line.find_first_of(sepperator));
			value = line.substr(line.find_first_of(sepperator) + 1, line.length() - 1);

			dictionary_->add(key, value);
		}
	} else {
		throw logic_error("Could not open config file");
	}
}

