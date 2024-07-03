#include "scrabbleScore.h"
#include<map>
#include <vector>
#include <cctype>

namespace cxnajdersCode {
    // I like to make my code very explicit and easy to read.
    // I am aware it can be also very tedious and less memory/speed efficient.

    namespace {
        // empty namespace makes it available only in this unit (just like static keytword in c)

        const std::map<std::vector<char>, int> cLettersAndPointsMap = { 
            { { 'A', 'E', 'I', 'O', 'U', 'L','N', 'R', 'S', 'T' }, 1 },
            { { 'D', 'G' }, 2 },
            { { 'B', 'C', 'M', 'P' }, 3 },
            { { 'F', 'H', 'V', 'W', 'Y' }, 4 },
            { { 'K' }, 5 },
            { { 'J', 'X' }, 8 },
            { { 'Q', 'Z' }, 10 },
        };
    }

    int countScrabbleScore(const std::string& word)
    {    
        int score = 0;
        bool currentLetterChecked;
        for(const char wordLetter: word)
        {
            currentLetterChecked = false;
            for(const auto& mapRecord: cLettersAndPointsMap)
            {
                if(currentLetterChecked)
                    break;
                
                for(const char mapLetter: mapRecord.first)
                {
                    if (std::toupper(wordLetter) == mapLetter)
                    {
                        score += mapRecord.second;
                        currentLetterChecked = true;
                        break;
                    }
                }
            }
        }
        
        return score;

        // This function looks pretty awful
        // Wonder if there's a better way like using letters ascii code
    }
}

namespace bronkosCode {
    namespace {
        const int weights[] = {
            1, // A
            3, // B
            3, // C
            2, // D
            1, // E
            4, // F
            2, // G
            4, // H
            1, // I
            8, // J
            5, // K
            1, // L
            3, // M
            1, // N
            1, // O
            3, // P
            10, // Q
            1, // R
            1, // S
            1, // T
            1, // U
            4, // V
            4, // W
            8, // X
            4, // Y
            10, // Z
        };
    }

    int countScrabbleScore(const std::string& word)
    {    
        int score = 0;
        
        for (const char wordLetter: word) {
            score += weights[std::toupper(wordLetter) - 'A'];
        }
        
        return score;
    }
}