%%writefile paper_snake_rock.cpp
#include <iostream>
using namespace std;

//Declair check answer
char check_answer(char answer)
{
  while ( answer != 'r' && answer != 'R' && answer != 'p' && answer != 'P' && answer!= 's' && answer != 'S'  )
  {
    cout << "Please enter a conrect answer: ";
    cin >> answer;
  }
  return answer;
}


//Declair computer's choice
int get_computer_choice()
{
srand(time(0));
int num;
char choice;
num = rand() %3 +1; //range 3 starting from 1
choice = 'r';
if (num == 1)
{
  choice = 'r';
}
else if (num == 2)
{
  choice = 'p';
}
else
{
  choice = 's';
}
cout << "Computer's choice is: " << choice << endl;
return choice;
}


//Declair users choice
char get_user_choice()
{
  char answer, correct_answer;
  cout << "Rock Paper and Scissor!" << endl;
  cout << "Choose one of the following" << endl;
  for (int i = 0; i < 10; i++) {
    cout << "---";
  }
 cout << endl;
 cout << "r or R for rock" << endl;
 cout << "p or P for paper" << endl;
 cout << "s or S for scissor" << endl;
 cout << "Type your answer: ";
 cin >> answer;
 correct_answer = check_answer(answer);
 //cout << "You Choose: " << correct_answer << endl;
  return answer;
}


//Declair the winner
char get_winner(char Uchoice, char PCchoice)
{
 char winner; // = 'C;
 if  ((Uchoice == 'r' || Uchoice =='R') && (PCchoice == 'p'))
 {
  winner = 'C';
 }
 if  ((Uchoice == 'p' || Uchoice =='P') && (PCchoice == 's'))
 {
  winner = 'C';
 }
 else if ((Uchoice == 's' || Uchoice =='S') && (PCchoice == 'r'))
 {
  winner = 'C';
 }
 else if ((Uchoice == 'r' || Uchoice =='R') && (PCchoice == 's'))
 {
  winner = 'Y';
 }
 else if ((Uchoice == 'p' || Uchoice =='P') && (PCchoice == 'r'))
 {
  winner = 'Y';
 }
  else if ((Uchoice == 's' || Uchoice =='S') && (PCchoice == 'p'))
 {
  winner = 'Y';
 }
 else
 {
  winner = 'T';
 }
 if (winner == 'C')
  {
    cout << "You LOSE, try again";
  }
  else if (winner == 'Y')
  {
    cout << "You WIN!";
  }
  else{
    cout << "Tie game";
  }
 return 0;
}


int main()
{
  char Uchoice, PCchoice, winner;
  Uchoice = get_user_choice();
  PCchoice = get_computer_choice();
  get_winner(Uchoice, PCchoice);
return 0;
}
