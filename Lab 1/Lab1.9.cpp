#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double height;
    
    const double GRAVITY = 9.8;
    const double VELOCITY_THRESHOLD = 1.0;
    
    double frictionLoss = 0.40;
    double airResistLoss = 0.01;
    double wearTearLoss = 0.015;
    
    double bounceFactor = 1.0 - (frictionLoss + airResistLoss + wearTearLoss);

    cout << "Enter the initial height (in meters): ";
    cin >> height;

    int bounces = 0;
    double velocity = sqrt(2 * GRAVITY * height);

    while (velocity > VELOCITY_THRESHOLD) {
        bounces++;
        
        height = height * bounceFactor;
        velocity = sqrt(2 * GRAVITY * height);
    }

    cout << "Total number of bounces: " << bounces << endl;

    return 0;
}