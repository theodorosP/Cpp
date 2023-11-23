%%writefile Casino_guess_number.cpp
#include <iostream>
#include <cmath>
#include <sstream>
#include <limits>
using namespace std;

//Check for letters
bool check_for_letters(string inp){
    bool has_letters = false;
    for (char i : inp){
        if (!isdigit(i)){
            has_letters = true;
        }
    }
    return has_letters;
}


//Check for numbers
bool check_for_numbers(string inp){
    bool has_numbers = false;
    for (char i : inp){
        if (isdigit(i)){
            has_numbers = true;
        }
    }
    return has_numbers;
}

//Get user's name
string get_user_name(){
    string input;
    bool has_numbers;
    while(true){
        cout << "Give your full name" << endl;
        getline(cin, input);
        has_numbers = check_for_numbers(input);
        if (has_numbers == true){
            cout << "Wrong input, your name can not have letters" << endl;
        }
        else{
            break;
        }
    }
		cout << "Your name is: " << input << endl;
    return input;
}


//Get user's deposit/bet
string get_user_deposit_bet(string deposit_bet){
    string input;
    bool has_letters;
    while(true){
        cout << "Give your "<< deposit_bet << endl;
        getline(cin, input);
        has_letters = check_for_letters(input);
        if (has_letters == true){
            cout << "Wrong input, your "<< deposit_bet <<" should not have any letters" << endl;
        }
        else{
            break;
        }
    }
        cout << "Your " << deposit_bet << "is: $" << input << endl;
    return input;
}

//Check deposit and betting ammount
string check_deposit_bet(string deposit, string bet){
    double d_deposit, d_bet; //d stands for double
    string Udeposit_string, Ubet_string;
    while (true){
        d_deposit = stod(deposit);
        d_bet = stod(bet);
        if (d_deposit > d_bet){
            cout << "You can continue, deposit is greater than your bet." << endl;
            Udeposit_string = deposit;
            Ubet_string = bet;
            break;
        }
        else{
            cout << "Bet smaller than deposit, enter ammounts again" << endl;
            deposit = get_user_deposit_bet("deposit");
            bet = get_user_deposit_bet("bet");
        }
    }
    return Udeposit_string, Ubet_string;
}

//Get user's choice
string get_user_choice()
{
	string input;
    bool has_letters;
	while (true)
	{
		cout << "Please give a number between 1 - 10, 1 and 10 included" << endl;
		cin >> input;
        has_letters = check_for_letters(input);
		if (cin.fail() || has_letters == true || stod(input) < 1 || stod(input) > 10 || stod(input) != floor(stod(input)))
		{
			cout << "You gave a wrong number, please try again" << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
		    cout << "Your choice is " << input << endl;
            break;
		}
	}
	return input;
}

//Get computer's choice
string get_PC_choice(){
	int pc_input;
	string pc_input_string;
	srand(time(0));
	pc_input = rand() %10 +1; //Randomly pick up a number from 1 to 10
	cout << "The number selected by the computer is: " << pc_input <<endl;
	pc_input_string = to_string(pc_input);
	return pc_input_string;
}


int main()
{
	string Uname, Udeposit, Ubet, Uchoice, PCchoice;
	Uname = get_user_name();
	Udeposit = get_user_deposit_bet("deposit");
  Ubet = get_user_deposit_bet("bet");
  Udeposit, Ubet = check_deposit_bet(Udeposit, Ubet);
  Uchoice = get_user_choice();
  PCchoice = get_PC_choice();
	return 0;
}
