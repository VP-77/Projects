//Riley Nadwodny
//CSCE 2004

//Calculate and print weight of rebar based on dimensions
//How many bundles of rebar the truck can carry

#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    
    int numOfRebar = 0, weightLimit = 0; //Int variables for pieces of rebar and weight limit
    float rebarDiameter = 0, rebarLength = 0, rebarRadius = 0, rebarWeight; //Float variables for diameter (radius = diameter / 2) and length (height) of rebar
    float rebarBundleWeight = 0, rebarVolume = 0; //Float variable for weight of rebar bundles and rebarVolume
    float steelDensity = .284; //Float for density of steel = .284
    float rebarOnTruck = 0; //Float variable for number of rebar bundles the truck can carry
    const double PI = 3.1415926535897; //Const for PI
    
    
    cout << "Hello! This program will calculate how many bundles of rebar your truck can carry!" << endl; //Let user know what program does
    
    cout << "Enter the diameter of your rebar in inches: "; //Gets dimensions of the rebar from user
    cin >> rebarDiameter;
    cout << "Enter the length of your rebar in feet: ";
    cin >> rebarLength;
    rebarLength = (rebarLength * 12); //Convert feet to inches
    cout << "Enter the number of rebar pieces in a bundle: "; //Ask user for how many pieces of rebar
    cin >> numOfRebar;
    cout << "Enter the weight limit of your truck: "; //Ask user for weight limit of their truck
    cin >> weightLimit;
    cout << endl;
    
    rebarRadius = rebarDiameter / 2;  //Get radius from rebarDiameter
    
    rebarVolume = PI * (rebarRadius * rebarRadius) * rebarLength; //Volume = PI r^2 * h;
    
    rebarWeight = steelDensity * rebarVolume; //Weight of one rebar
    
    cout << "One piece of rebar weighs " << rebarWeight << " lbs." << endl; //Output weight of rebar based on it's dimensions
    
    rebarBundleWeight = rebarWeight * numOfRebar; //Weight of rebar bundle = weight of one rebar * pieces of rebar
    
    rebarOnTruck = weightLimit / rebarBundleWeight; //Rebar truck can carry = Weight limit / weight of rebar bundle
    
    cout << "Here's how many bundles you can put on your truck: " << rebarOnTruck << " bundles of rebar." << endl;

    return 0;
}