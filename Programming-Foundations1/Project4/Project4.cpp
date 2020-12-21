//------------------------------------------------------------
// Purpose: To implement an interactive horoscope generator.  
//          The user will enter their birthdate and answer a few
//          questions, and the program will print some advice.
//
// Author:  John Gauch - Created skeleton program.
// Author:  Riley Nadwodny - Finished implementation of program.
//------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

//------------------------------------------------------------
// Purpose: To prompt the user to enter their birthdate.
// Input:   None.
// Output:  The user's birth year, month, day.
//------------------------------------------------------------
void GetBirthDate(int& year, string& month, int& day)
{
	// Prompt user for birth year
	year = 0;
	while ((year < 1900) || (year > 2019))
	{
		cout << "Enter the year you were born [1900..2019]: ";
		cin >> year;
	}

	// Prompt user for birth month
	month = "";
	while (month != "Jan" && month != "Feb" && month != "Mar" &&
		month != "Apr" && month != "May" && month != "Jun" &&
		month != "Jul" && month != "Aug" && month != "Sep" &&
		month != "Oct" && month != "Nov" && month != "Dec")
	{
		cout << "Enter the month you were born [Jan..Dec]: ";
		cin >> month;
	}

	// Prompt user for birth day
	day = 0;
	while ((day < 1) || (day > 31))
	{
		cout << "Enter the day you were born [1..31]: ";
		cin >> day;
	}
}

//------------------------------------------------------------
// Purpose: To calculate the user's karma.
// Input:   None.
// Output:  The user's karma score.
//------------------------------------------------------------
int GetKarma()
{
	int answer = 0;
	cout << "How many people have you said hello to today? ";
	cin >> answer;

	// Silly karma calculation
	if (answer <= 0)
		return 0;
	else if (answer == 42)
		return 100;
	else
		return (answer / 2) + (rand() % 5);
}

//------------------------------------------------------------
// Purpose: Calculate the user's astrological sign.
// Input:   The user's birth month, day.
// Output:  The user's astrological sign.
//------------------------------------------------------------
string GetSign(const string month, const int day)
{
	if ((month == "Mar" && day >= 21) || (month == "Apr" && day <= 20))
		return "Aries";
	if ((month == "Apr" && day >= 21) || (month == "May" && day <= 21))
		return "Taurus";
	if ((month == "May" && day >= 22) || (month == "Jun" && day <= 21))
		return "Gemini";
	if ((month == "Jun" && day >= 22) || (month == "Jul" && day <= 22))
		return "Cancer";
	if ((month == "Jul" && day >= 23) || (month == "Aug" && day <= 22))
		return "Leo";
	if ((month == "Aug" && day >= 23) || (month == "Sep" && day <= 23))
		return "Virgo";
	if ((month == "Sep" && day >= 24) || (month == "Oct" && day <= 23))
		return "Libra";
	if ((month == "Oct" && day >= 24) || (month == "Nov" && day <= 22))
		return "Scorpio";
	if ((month == "Nov" && day >= 23) || (month == "Dec" && day <= 21))
		return "Sagittarius";
	if ((month == "Dec" && day >= 22) || (month == "Jan" && day <= 20))
		return "Capricorn";
	if ((month == "Jan" && day >= 21) || (month == "Feb" && day <= 19))
		return "Aquarius";
	if ((month == "Feb" && day >= 20) || (month == "Mar" && day <= 20))
		return "Pisces";
	return "";
}

//------------------------------------------------------------
// Purpose: Romance prediction
// Input:   The user's karma score.
// Output:  Prediction message.
//------------------------------------------------------------
string Romance(const int karma)
{
	int choice = (karma * 17) % 5;
	string message = "";
	switch (choice)
	{
	case 0:
		message = "Maybe your date would like to see a romantic comedy?";
		break;
	case 1:
		message = "I think it is singles night at the local pub.";
		break;
	case 2:
		message = "You should sit by the fire and read a good romance novel.";
		break;
	case 3:
		message = "Searching online for the perfect date seldom works.";
		break;
	case 4:
		message = "Love is not in the air tonight, time to play video games.";
		break;
	default:
		message = "Romance prediction is impossible.";
		break;
	}
	return message;
}

//------------------------------------------------------------
// Purpose: Money prediction
// Input:   The user's birth year.
// Output:  Prediction message.
//------------------------------------------------------------
void Money(const int year, string& message)
{
	int choice = (2019 - year) / 10;
	switch (choice)
	{
	case 0:
		message = "Ask your parents for their spare change.";
		break;
	case 1:
		message = "This is a good time to your parents for a bigger allowance.";
		break;
	case 2:
		message = "You can save more money by buying less beer.";
		break;
	case 3:
		message = "Try to save a little extra for a down payment on a house.";
		break;
	case 4:
		message = "Yikes, your children's tuition bills are due soon.";
		break;
	default:
		message = "Money prediction is impossible.";
		break;
	}
}

//------------------------------------------------------------
// Purpose: Job prediction
// Input:   The user's birth year.
// Output:  Prediction message.
//------------------------------------------------------------
string Job(const int day, const int karma)
{
	string message = "";
	if ((day < 15) && (karma > 5))
		message = "Your boss looks generous today, time to ask for a raise.";
	else if ((day > 15) && (karma < 5))
		message = "Prepare for bad news, your company profits are down.";
	else if ((day == 15) && (karma == 5))
		message = "Bad news, your company is declaring bankruptcy.";
	else if (karma > day)
		message = "Great news, your company just went public!";
	else if (karma <= day)
		message = "It looks like a chance for some overtime.";
	else
		message = "Money prediction is impossible.";
	return message;
}

//------------------------------------------------------------
// Purpose: Family prediction
// Input:   The user's birth year and karma.
// Output:  Prediction message.
//------------------------------------------------------------
string Family(const int year, const int karma)
{
	string message = "";
	int choice = ((year * karma) * rand()) / 100000;

	if ((choice > 0) && (choice < 1000))
		message = "You and your family have some bright times ahead.";
	else if ((choice > 1000) && (choice < 2000))
		message = "There's some tension within your family; talk to them about what may be going on.";
	else if ((choice > 2000) && (choice < 3000))
		message = "A family outing is a great idea for the weekend.";
	else if ((choice > 3000) && (choice < 4000))
		message = "Hard times may be hard. Be careful.";
	else if ((choice > 4000) && (choice < 5000))
		message = "You may be getting a new family member soon; perhaps a dog or a cat, or even a baby?";
	else if (choice > 5000)
		message = "Family prediction is impossible.";
	return message;
}

//------------------------------------------------------------
// Purpose: Health prediction
// Input:   The user's birth day and birth year.
// Output:  Prediction message.
//------------------------------------------------------------
void Health(const int day, const int year, string& HealthMessage)
{
	int choice = (day * year) % 5;

	if (choice == 0)
		HealthMessage = "You are in an incredibly well period of health!";
	else if (choice == 1)
		HealthMessage = "Beware of an impending sickness; perhaps start taking allergy and flu medication.";
	else if (choice == 2)
		HealthMessage = "Someone close to you is about to fall ill.";
	else if (choice == 3)
		HealthMessage = "Everyone around you is very healthy! Do not fear any illnesses any time soon.";
	else if (choice == 4)
		HealthMessage = "You may want to see a doctor...";
	else
		HealthMessage = "Health prediction is impossible.";

}

//------------------------------------------------------------
// Purpose: Silly prediction
// Input:   TO BE ADDED 
// Output:  Prediction message.
//------------------------------------------------------------
string Silly(const int year, const int day, const int karma)
{
	int choice = (((year * karma) / day) % 10 );
	string message;

	switch (choice)
	{
	case 0:
		message = "Great things are ahead! You are going to inherit a TRILLION dollars, become president of the universe, and recreate dinosaurs and create a real Jurassic Park!";
		break;
	case 1:
		message = "You are going to win the lottery soon, so go big! But don't take my word for it- follow your gut. Save/spend your winnings wisely, and don't tell your friends that you won!";
		break;
	case 3:
		message = "Now would be a good time to adopt a White Tiger. You can have a big, furry cat for life! Just don't let the police find out.";
		break;
	case 4:
		message = "You should definitely consider a mohawk. It would complete the look.";
		break;
	case 5:
		message = "You should definitely consider a mullet. All the girls love a good mullet.";
		break;
	case 6:
		message = "You are going to avert a serious natural disaster in the area soon using only trigonomotry.";
		break;
	case 7: 
		message = "One of your pets is going to go to space soon. They're going to become famous. Rake in the royalties when they get back.";
		break;
	case 8:
		message = "Whatever happened today, you still have the loving warmth and comfort of your bed tonight- that's the best love of all.";
		break;
	case 9:
		message = "Login to every website you can find today, and you will find out the true meaning of the internet and life today. (Hint: The answer may be 42.)";
		break;
	default:
		message = "Your next 365 meals are going to comprise of candy served in frying pans, apple juice served in wine flutes, and Chili's lava cakes topped with designer Tiffany jewlery.";
		break;
	}

	return message;
}

//------------------------------------------------------------
// Purpose: Print user's horoscope.
// Input:   The user's birth year, month, day, karma.
// Output:  None.
//------------------------------------------------------------
void PrintHoroscope(const int year, const string month,
	const int day, const int karma)
{
	// Print user's sign
	string UserSign;
	UserSign = GetSign(month, day);
	cout << "\nYour astrological sign is " << UserSign << endl;

	// Print romance prediction
	string PredictRomance;
	PredictRomance = Romance(karma);
	cout << PredictRomance << endl;

	// Print money prediction
	string PredictMoney;
	Money(year, PredictMoney);
	cout << PredictMoney << endl;

	// Print job prediction
	string PredictJob;
	PredictJob = Job(day, karma);
	cout << PredictJob << endl;

	// Print family prediction
	string PredictFamily;
	PredictFamily = Family(year, karma);
	cout << PredictFamily << endl;

	// Print health prediction
	string PredictHealth;
	Health(day, year, PredictHealth);
	cout << PredictHealth << endl;

	// Print silly prediction
	string SillyPrediction;
	SillyPrediction = Silly(year, day, karma);
	cout << SillyPrediction << endl;
}

//------------------------------------------------------------
// Purpose: The main program.
// Input:   None.
// Output:  None.
//------------------------------------------------------------
int main()
{
	// Initialize random number generator
	srand(time(NULL));

	// Get user's birthday
	int year, day;
	string month;
	GetBirthDate(year, month, day);

	// Get user's karma points
	double karma;
	karma = GetKarma();

	// Print horoscope
	PrintHoroscope(year, month, day, karma);

	return 0;
}