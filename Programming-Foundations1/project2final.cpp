//Riley Nadwodny
//CSCE 2004
//9/16/19

//Provide experience with I/O commands in C++ & conditional statements
//Get food preferences from customers, deliver a surprise meal, and output the cost of the meal

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int meatScale, vegetablesScale, pastaScale, potatoesScale, chocolateScale, fruitScale = 0; //What the user likes
	double budget = 0; //Budget of the customer. <$15=no app, <$10=no main course, <$20=no dessert
	int appetizer = 5, mainCourse = 10, dessert = 5; //Prices for appetizer, main course, and dessert servings
	double totalCost = 0; //Total cost of the meal
	double mealTax = 0; //Tax for the customer's meal
	double numApp, numMeal, numDessert = 0; //Number of appetizer, main courses, or desserts the customer got
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
	cout << endl;


	//If the scores are lower than 1 or higher than 100, set to 1 or 100 respectively
	if (meatScale < 1) {
		meatScale = 1;
	}

	if (meatScale > 100) {
		meatScale = 100;
	}

	if (vegetablesScale < 1) {
		vegetablesScale = 1;
	}

	if (vegetablesScale > 100) {
		vegetablesScale = 100;
	}

	if (pastaScale < 1) {
		pastaScale = 1;
	}

	if (pastaScale > 100) {
		pastaScale = 100;
	}

	if (potatoesScale < 1) {
		potatoesScale = 1;
	}

	if (potatoesScale > 100) {
		potatoesScale = 100;
	}

	if (chocolateScale < 1) {
		chocolateScale = 1;
	}

	if (chocolateScale > 100) {
		chocolateScale = 100;
	}

	if (fruitScale < 1) {
		fruitScale = 1;
	}

	if (fruitScale > 100) {
		fruitScale = 100;
	}

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
		else if ((meatScale >= vegetablesScale) && (pastaScale >= potatoesScale)) {
			surpriseMeal = "Main course: Spaghetti and meat sauce";
		}
		else if ((vegetablesScale >= meatScale)) {
			surpriseMeal = "Main course: Pasta primavera";
		}
		else if ((meatScale >= vegetablesScale) && (potatoesScale >= pastaScale)) {
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

		numApp = 1;
		numMeal = 1;
		numDessert = 1;
	}

	else if (budget > 15 && budget < 20) { //If the customers budget is between $15 and $20

		surpriseApp = "Appetizer: None";

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


		if ((chocolateScale < 10) && (fruitScale < 10)) { //Dessert section
			surpriseDessert = "Dessert: Vanilla ice cream";
		}
		else if ((fruitScale > chocolateScale)) {
			surpriseDessert = "Dessert: Apple pie";
		}
		else if ((chocolateScale > fruitScale) || (chocolateScale == fruitScale)) {
			surpriseDessert = "Dessert: Chocolate cake";
		}

		numApp = 0;
		numMeal = 1;
		numDessert = 1;
	}

	//Selection if the  budget is less than $10, or between $10 and $15
	else if ((budget <= 10) || ((budget >= 10) && (budget < 15))) {

		if ((vegetablesScale < 10) && (meatScale < 10)) {      //Appetizer section
			surpriseApp = "Appetizer: Garlic Bread";
		}
		else if (vegetablesScale > meatScale) {
			surpriseApp = "Appetizer: Garden Salad";
		}
		else if ((meatScale > vegetablesScale) || (meatScale == vegetablesScale)) {
			surpriseApp = "Appetizer: Chicken Wings";
		}

		surpriseMeal = "Main course: None";


		if ((chocolateScale < 10) && (fruitScale < 10)) {
			surpriseDessert = "Dessert: Vanilla ice cream";
		}
		else if ((fruitScale > chocolateScale)) {
			surpriseDessert = "Dessert: Apple pie";
		}
		else if ((chocolateScale > fruitScale) || (chocolateScale == fruitScale)) {
			surpriseDessert = "Dessert: Chocolate cake";
		}
		numApp = 1;
		numMeal = 0;
		numDessert = 1;
	}

	//Outputs the customers food
	cout << surpriseApp << endl;
	cout << surpriseMeal << endl;
	cout << surpriseDessert << endl << endl;

	//Calculate total cost of the meal, then meal tax
	totalCost = ((numApp * appetizer) + (numMeal * mainCourse) + (numDessert * dessert));
	mealTax = (totalCost * .07);

	//Outputs bill to customer; add meal tax to the total cost of the meal for the total cost + tax
	cout << "Your bill for the meal is...\n";
	cout << "Meal: $" << totalCost << endl;
	cout << "Tax: $" << setprecision(2) << fixed << mealTax << endl;
	totalCost = totalCost + mealTax;
	cout << "Total: $" << setprecision(2) << fixed << totalCost << endl << endl;

	cout << "Thank you for coming to John's Restaurant! Please come again!\n";

	return 0;
}