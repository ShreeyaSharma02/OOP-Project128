#include "SocialBattery.h"

SocialBattery::SocialBattery()
    : current_battery(100), max_battery(100) {}

void SocialBattery::reduce_battery(int amount) {
    current_battery -= amount;
    if (current_battery < 0) {
        current_battery = 0;
    }
}

void SocialBattery::recharge_battery() {
    current_battery = max_battery;
}

int SocialBattery::get_current_battery() const {
    return current_battery;
}
