#ifndef SOCIALBATTERY_H
#define SOCIALBATTERY_H

class SocialBattery {
private:
    int current_battery;
    const int max_battery;

public:
    SocialBattery();
    void reduce_battery(int amount);
    void recharge_battery();
    int get_current_battery() const;
};

#endif 
