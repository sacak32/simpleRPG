#pragma once

#include <string>

class Character;

class Observer {
public:
    virtual void onNotify(const Character& character, const std::string& event) = 0;
    virtual ~Observer() = default;
};