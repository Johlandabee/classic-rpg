#pragma once
#include "Dictionary.h"

using namespace std;
using namespace Common;

namespace Engine
{
    class Config {
        Dictionary<string, string>* props = nullptr;
        string fileName;

        void loadFile() const;

    public:
        explicit Config(string fileName);
        ~Config();

        bool getBooleanValue(string const& key, bool defaultValue) const;
        double getDoubleValue(string const& key, double defaultValue) const;
        int getIntValue(string const& key, int defaultValue) const;
        string getStringValue(string const& key, string defaultValue = "") const;
    };

}