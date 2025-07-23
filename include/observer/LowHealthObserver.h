#pragma once

#include "Observer.h"

class LowHealthObserver : public Observer {
public:
    void onNotify(const Character& character, const std::string& event) override;
};