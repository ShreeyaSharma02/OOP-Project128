/* Testing social battery by initialiasing it, reducing it, and then recharging the battery

Expected Output:
Initial battery: 100
Battery after reduction: 80
Battery after recharge: 100

*/

#include <iostream>
#include "SocialBattery.h"

void test_social_battery() {
    SocialBattery battery;

    // Testing initial battery level
    std::cout << "Initial battery: " << battery.get_current_battery() << std::endl;

    // Testing reducing battery
    battery.reduce_battery(20);
    std::cout << "Battery after reduction: " << battery.get_current_battery() << std::endl;

    // Testing recharging battery
    battery.recharge_battery();
    std::cout << "Battery after recharge: " << battery.get_current_battery() << std::endl;
}

int main() {
    test_social_battery();
    return 0;
}


