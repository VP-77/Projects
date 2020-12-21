//Riley Nadwodny
//CSCE 2004
//9/16/19

//Provide experience with I/O commands in C++ & conditional statements
//Get food preferences from customers, deliver a surprise meal, and output the cost of the meal

#include <iostream>
using namespace std;

int main ()
{
    int meatScale, vegetablesScale, pastaScale, potatoesScale, chocolateScale, fruitScale = 0; //What the user likes
    double budget = 0; //Budget of the customer. <$15=no app, <$10=no main course, <$20=no dessert
    int appetizer = 5, mainCourse = 10, dessert = 5; //Prices for appetizer, main course, and dessert servings
    double totalCost = 0; //Total cost of the meal
    string surpriseApp, surpriseMeal, surpriseDessert = ""; //String to store choices into to output to customer at the end
    
    cout << "Welcome to John's Restraurant\n" << endl;
    cout << "The chef will cook a surprise meal for you based on the answers to the following questions!\n" << endl;
    
    cout << "How much do you like meat on a scale from 1 to 100? ";
    cin >> meatScale;
    cout << "How much do you like vegetables on a scale from 1 to 100? ";
    cin >> vegetablesScale;
    cout << "How much do you like pasta on a scale from 1 to 100? ";
    cin >> pastaScale;
    cout << "How much do you like potatoes on a scale from 1 to 100? ";
    cin >> potatoesScale;
    cout << "How much do you like chocolate on a scale from 1 to 100? ";
    cin >> chocolateScale;
    cout << "How much do you like fruit on a scale from 1 to 100? ";
    cin >> fruitScale;
    cout << "And lastly, what is your budget for this meal? ";
    cin >> budget;
    
    cout << "The chef's surprise meal for you consists of...\n";
    
    if (budget >= 20) {                                         //Budget is greater than 20
        if ((vegetablesScale < 10) && (meatScale < 10)) {      //Appetizer section
            surpriseApp = "Appetizer: Garlic Bread";
        }
        else if (vegetablesScale > meatScale) {
            surpriseApp = "Appetizer: Garden Salad";
        }
        else if ((meatScale > vegetablesScale) || (meatScale == vegetablesScale)) {
            surpriseApp = "Appetizer: Chicken Wings";
        }
        
        
        if ((meatScale < 10) && (vegetablesScale < 10) && (pastaScale < 10) && (potatoesScale < 10)) {  //Main course section
            surpriseMeal = "Main course: Cheese omelet";
        }
        else if ((meatScale > vegetablesScale) && (pastaScale > potatoesScale)) {
            surpriseMeal = "Main course: Spaghetti and meat sauce";
        }
        else if ((vegetablesScale > meatScale)) {
            surpriseMeal = "Main course: Pasta primavera";
        }
        else if ((meatScale > vegetablesScale) && (potatoesScale > pastaScale)) {
            surpriseMeal = "Main course: Steak and baked potato";
        }
        
        
        if ((chocolateScale < 10) && (fruitScale < 10)) {
            surpriseDessert = "Dessert: Vanilla ice cream";
        }
        else if ((fruitScale > chocolateScale)) {
            surpriseDessert = "Dessert: Apple pie";
        }
        else if ((chocolateScale > fruitScale) || (chocolateScale == fruitScale)) {
            surpriseDessert = "Dessert: Chocolate cake";
        }
    }
    
    
    cout << surpriseApp << endl;
    cout << surpriseMeal << endl;
    cout << surpriseDessert << endl;
        
    //If budget is <=$15, customer gets main course and dessert
        //if customer meatScale > vegetablesScale && potatoesScale > pastaScale, steak and baked potato
        //else if customer meatScale > vegetablesScale && pastaScale > potatoesScale, spaghetti and meat sauce
        //else if cusomter vegetablesScale > meatScale, pasta primavera
        //else if meatScale < 10 && vegetablesScale < 10 && pastaScale < 10 && potatoesScale < 10, cheese omelet
        
    //If budget is <=$10, customer gets main course
        
    
    return 0;
}