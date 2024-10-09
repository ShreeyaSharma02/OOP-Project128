#ifndef SOCIALBATTERY_H
#define SOCIALBATTERY_H

class SocialBattery {
private:
    int current_battery;
    int max_battery;
    int min_battery;

public:
    SocialBattery(int max, int min, int initial)
        : max_battery(max), min_battery(min), current_battery(initial) {}

    void reduce_battery() {
        current_battery = std::max(current_battery - 10, min_battery);
    }

    void recharge_battery() {
        current_battery = std::min(current_battery + 20, max_battery);
    }

    int get_current_battery() const {
        return current_battery;
    }

    bool battery_low() const {
        return current_battery <= 0;
    }
};

#endif // SOCIALBATTERY_H
