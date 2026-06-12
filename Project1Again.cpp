#include <iostream>   
#include <cstdlib>    
#include <ctime>      
#include <string>

using namespace std;  

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;          
    enGameChoice Player1Choice;    
    enGameChoice ComputerChoice;    
    enWinner Winner;               
    string WinnerName;               
};

struct stGameResults
{
    short GameRounds = 0;       
    short Player1WinTimes = 0;   
    short ComputerWinTimes = 0;  
    short DrawTimes = 0;         
    enWinner GameWinner;         
    string WinnerName = "";      
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

enGameChoice ReadPlayer1Choice()
{
    short Choice;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);

    return (enGameChoice)Choice;
}

short HowManyRounds()
{
    short Rounds;
    do
    {
        cout << "How Many Rounds Do You Want To Play : [1] To [9]? : ";
        cin >> Rounds;
    } while (Rounds > 9 || Rounds < 1);
    cout << "\n";

    return Rounds;
}

enWinner WhoWonTheRound(const stRoundInfo& RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
            return enWinner::Computer;
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
            return enWinner::Computer;
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
            return enWinner::Computer;
        break;
    }
    
    // إذا لم يكن تعادل ولم يفز الكمبيوتر، إذن اللاعب هو الفائز حتماً
    return enWinner::Player1;
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)  
        return enWinner::Computer;
    else 
        return enWinner::Draw;
}

string ChoiceName(enGameChoice Choice)
{
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoices[Choice - 1];
}

string WinnerNameText(enWinner Winner)
{
    string arrWinnerName[3] = { "Player1", "Computer", "No Winner (Draw)" };
    return arrWinnerName[Winner - 1];
}

void PrintRoundResults(const stRoundInfo& RoundInfo)
{
    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
    cout << "_________________________________________\n" << endl;
}

stGameResults PlayGame(short Rounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;

    for (int GameRound = 1; GameRound <= Rounds; GameRound++)
    {
        cout << "             Round [" << GameRound << "] begins:\n";

        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerNameText(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }
    
    enWinner FinalWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
    stGameResults Results;
    Results.GameRounds = Rounds;
    Results.Player1WinTimes = Player1WinTimes;
    Results.ComputerWinTimes = ComputerWinTimes;
    Results.DrawTimes = DrawTimes;
    Results.GameWinner = FinalWinner;
    Results.WinnerName = WinnerNameText(FinalWinner);
    
    return Results;
}

string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 1; i <= NumberOfTabs; i++)
    {
        t = t + "\t";
    }
    return t;
}

void ShowGameOver()
{
    cout << Tabs(2) << "______________________________________________________________\n\n";
    cout << Tabs(2) << "                  +++ G A M E  O V E R  +++ \n";
    cout << Tabs(2) << "______________________________________________________________\n\n";
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F"); // أخضر عند فوز اللاعب
        break;
    case enWinner::Computer:
        system("color 4F"); // أحمر عند فوز الكمبيوتر
        cout << "\a";       // صوت تنبيه
        break;
    default:
        system("color 6F"); // أصفر في حال التعادل
        break;
    }
}

void ShowFinalGameResults(const stGameResults& GameResults)
{
    cout << Tabs(2) << "-------------------- [ GAME RESULT ] --------------------\n\n";
    cout << Tabs(2) << " Game Rounds        : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << " Player Won Times   : " << GameResults.Player1WinTimes << endl;
    cout << Tabs(2) << " Computer Won Times : " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << " Draw Times         : " << GameResults.DrawTimes << endl;
    cout << Tabs(2) << " Final Winner       : " << GameResults.WinnerName << endl;
    cout << Tabs(2) << "_______________________________________________________\n";
    SetWinnerScreenColor(GameResults.GameWinner);
}

void ResetScreen()
{
    system("cls");  
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(HowManyRounds()); 
        ShowGameOver();
        ShowFinalGameResults(GameResults);
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL)); 
    StartGame();  
    return 0;  
}
