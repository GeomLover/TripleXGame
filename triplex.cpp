#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty)
{
    std::cout << "You are a scret agent breaking into secure server room with a level of difficulty " << Difficulty;
    std::cout << ".\nYou need to enter the correct codes to continue..." << std::endl;
}
bool PlayGame(int LevelDifficulty)
{

    PrintIntroduction(LevelDifficulty);

    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    // std::cout << "CodeA : " << CodeA << "\nCodeB : " << CodeB << "\nCodeC : "<< CodeC << "\n";

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "Sum of the three codes : " << CodeSum << std::endl;
    std::cout << "Product of the three codes : " << CodeProduct << std::endl;
    
    bool bLevelComplete = false;
    int GuessA = 0, GuessB = 0, GuessC = 0;

    std::cout << "Enter your guess : " << std::endl;
    
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << std::endl;

    std::cout << "You entered: \n" << GuessA << "\n" << GuessB << "\n" << GuessC << "\n";

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    std::cout << "Sum of the player guesses : " << GuessSum << std::endl;
    std::cout << "Product of the player guesses : " << GuessProduct << std::endl;

    if ( (CodeSum == GuessSum) && (CodeProduct == GuessProduct) )
    {
        std::cout <<  "You win the difficulty level " << LevelDifficulty <<"!\n";
        bLevelComplete = true;
    }
    else
    {
        std::cout << "You lose the difficulty level " << LevelDifficulty << "! Try Again the difficulty level "<<LevelDifficulty<< "! \n \n";
        bLevelComplete = false;
    }
    return bLevelComplete;
}
int main()
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxLevelDifficulty = 10;
    

    bool bLevelComplete = false;
    
    while( LevelDifficulty <= MaxLevelDifficulty)
    {
        bLevelComplete = PlayGame(LevelDifficulty);
        if (bLevelComplete)
        {
            LevelDifficulty++;
        }        
        std::cin.clear();
        std::cin.ignore();
    }
    std::cout << "Congratulations! You have successfully completed all the diffulty levels of the game TripleX! \n";

    return 0;
}