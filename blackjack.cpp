#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void StartGame(string hand[], int &handValue, int &handCount, string cards[], int cardValues[], int cardCount[]);
void DisplayHand(string hand[], int handValue, int handCount);
void AddCard(string hand[], int &handValue, int &handCount, string cards[], int cardValues[], int cardCount[]);
void DetermineWinner(int user,int cpu);
void CompleteHand(string hand[],int &handValue,int handCount);

int main()
{
    string cards[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
    int cardValues[] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
    int cardCount[] = {4,4,4,4,4,4,4,4,4,4,4,4,4};

    string userHand[7];
    int userValue = 0;
    int handCount = 0;
    string cpuHand[7];
    int cpuValue = 0;
    int cpuHandCount = 0;
    int option;
    srand(time(0));
    while (true)
    {
        StartGame(userHand,userValue,handCount,cards,cardValues,cardCount);
        StartGame(cpuHand,cpuValue,cpuHandCount,cards,cardValues,cardCount);
        DisplayHand(userHand,userValue,handCount);
        DisplayHand(cpuHand,cpuValue,cpuHandCount);

        while (userValue != 21 && option != 2)
        {
			if (userValue == 21 || cpuValue == 21)
			{
				cout << "BLACKJACK!!!!!" << endl;
				break;
			}
			cout << "YOUR TURN!" << endl;
            cout << "Hit......press 1" << endl;
            cout << "Stand....press 2" << endl;
            cin >> option;

            switch(option)
            {
                case 1:
                    AddCard(userHand,userValue,handCount,cards,cardValues,cardCount);
                    break;
                case 2:
                    CompleteHand(userHand,userValue,handCount);
                    break;
            }

            if(userValue > 21)
            {
                cout << "Bust...You Lost" << endl;
                break;
            }
        }
        cout << "CPU TURN!" << endl;
        while(cpuValue < 17 && userValue <= 21)
        {
			if (cpuValue == 21)
			{
				break;
			}
            AddCard(cpuHand,cpuValue,cpuHandCount,cards,cardValues,cardCount);
            if( cpuValue > 21)
            {
                cout << "CPU Bust...You Won!" << endl;
                break;
            }
        }
        DetermineWinner(userValue,cpuValue);
        cout <<"Play again? 1...yes or 2...no ";
        cin >> option;
        cout << "----------------------------------" << endl;
        if (option == 2)
        {
            cout << "Thanks for playing!";
            break;
        }
    }
    return 0;
}

void StartGame(string hand[], int &handValue, int &handCount, string cards[], int cardValues[], int cardCount[])
{
    for (int i = 0; i < handCount; i++)
    {
        hand[i] = "";
    }
    handValue = 0;
    handCount = 0;
    for (int i = 0; i < 2; i++)
    {
        int card = 0;
        card = rand() % 13;
        hand[i] = cards[card];
        handValue = handValue + cardValues[card];
        cardCount[card]--;
        handCount++;
    }
}

void DisplayHand(string hand[], int handValue, int handCount)
{
    cout <<"Current Hand: ";
    for (int i = 0; i < handCount; i++)
    {
        cout << hand[i] << " ";
    }
    cout << "Value: " << handValue << endl;
}

void AddCard(string hand[], int &handValue, int &handCount, string cards[], int cardValues[], int cardCount[])
{
    int card = rand() % 13;
    while (true)
    {
        if (cardCount[card] <= 0)
        {
            card = rand() % 13;
        }
        else
        {
            hand[handCount] = cards[card];
            handValue = handValue + cardValues[card];
            cardCount[card]--;
            handCount++;
            DisplayHand(hand,handValue,handCount);
            break;
        }
    }
}

void DetermineWinner(int user,int cpu)
{
    if (user > cpu && user <= 21)
    {
        cout << "You Won!" << endl;
    }
    else if (user < cpu && cpu <= 21)
    {
        cout << "You Lost :(" << endl;
    }
    else if (user == cpu && cpu <= 21 && user <= 21)
    {
        cout << "Tie" << endl;
    }
}

void CompleteHand(string hand[],int &handValue,int handCount)
{
    for (int i = 0; i < handCount; i++)
    {
        if (hand[i] == "Ace" && handValue + 10 <= 21)
        {
            handValue == handValue + 10;
        }
    }
}



