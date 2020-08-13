//Preprocessor Directives
#include <iostream>
#include <string>
#include <ctime>

void RequestName(std::string name)
{
    //Requesting name of the player
    std::cout << "\n\nEnter Your Name\n";
    std::cin >> name;
    std::cout << "\n"
              << name << "! ";
}
void PrintIntroduction(int Difficulty)
{
    // Welcome Message on terminal
    std::cout << "You are a detective... You must enter the room " << Difficulty;
    std::cout << " and find the confidential documents...\n Enter correct code to enter server room \n\n";
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Declaration 3 variables and calculating code
    // const int CodeA = rand() %Difficulty++1; // adding offset +1 to avoid 0 
    // const int CodeB = rand() %Difficulty+1;
    // const int CodeC = rand() %Difficulty+1;
    const int CodeA = rand() %Difficulty+Difficulty; // adding offset +Difficulty to to avoid 0 and  
    const int CodeB = rand() %Difficulty+Difficulty; //increase difficulty level
    const int CodeC = rand() %Difficulty+Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print Sum and Product in Terminalb
    std::cout << std::endl; //<< called as insertion operator
    std::cout << "+ There are three numbers in the code\n";
    std::cout << "+ The codes add upto :- " << CodeSum << "\n";
    std::cout << "+ The codes multiply upto :- " << CodeProduct << "\n";
    std::cout << "***Please Enter your code***\n";

    //Storing Data guessed by the User
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC; // >> called as extraction operator
    std::cout << "You Entered : "
              << " " << GuessA << " " << GuessB << " " << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && CodeProduct == GuessProduct)
    {
        std::cout << "\nGreat! You've successfully unlocked the door! Grab the docs and Let's move to next level\n\n";
        return true;
    }
    else
    {
        std::cout << "\nYou've entered wrong code agent'! Try again and be careful\n\n";
        return false;
    }
}
int main() //main function
{
    srand(time(NULL)); // Creating a new Random Sequence based on time of the day
    const int MaxDifficulty = 10; 
    int LevelDifficulty = 1;
    std::string CodeName;
    RequestName(CodeName);
    while (true) //Loop the game till all the difficulties are clear
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (LevelDifficulty<=MaxDifficulty)
        {
            //Increase Difficulty Level
            ++LevelDifficulty;
        }
    }
    std::cout<<"Great Work Detective... You've got all the files... It's time to loose your heat!"
    return 0;
}