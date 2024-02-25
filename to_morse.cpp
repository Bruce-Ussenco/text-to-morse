#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// pairs of a letter and its morse translation
vector<pair<char, string>> pairs = {
    {' ', " "},
    {'a', ".-"},
    {'b', "-..."},
    {'c', "-.-."},
    {'d', "-.."},
};

int pairsCount = pairs.size();



string toMorse(char c);

int main(int argc, char **argv)
{
    cout << '\n';

    if (argc == 1) {
        cout << "[ERROR] Pass some text!\n\n";
        
        return 1;
    }
    if (argc > 2) {
        cout << "[ERROR] Pass a single argument\n"
             << "To do that, place your text inside \"\":\n"
             << "to_morse \"all the text you want to translate into morse code\"\n\n";

        return 1;
    }


    char *text = argv[1];
    string morse = "";

    cout << "Your text:\n" << text << "\n\n";

    for (int i = 0; text[i] != '\0'; i++) {
        if (i != 0) morse += ' ';

        char c = text[i];
        morse += toMorse(c);

        /*switch (c) {
            case ' ':
                morse += ' ';    break;
            case 'a':
                morse += ".-";   break;
            case 'b':
                morse += "-..."; break;
            case 'c':
                morse += "-.-."; break;
            default:
                morse += '?'; break;
        }*/
    }

    cout << "Morse translation:\n";
    cout << morse << "\n\n";

    return 0;
}

string toMorse(char c)
{
    for (int i = 0; i < pairsCount; i++) {
        pair p = pairs[i];

        if (c == p.first) {
            return p.second;
        }
    }

    return "?";
}

