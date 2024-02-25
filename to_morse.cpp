#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef struct Translator {
    char letter;
    string morse;
} Translator;

// pairs of a letter and its morse translation
vector<Translator> translators = {
    {' ', " "},
    {'a', ".-"},
    {'b', "-..."},
    {'c', "-.-."},
    {'d', "-.."},
    {'e', "."},
    {'f', "..-."},
    {'g', "--."},
    {'h', "...."},
    {'i', ".."},
    {'j', ".---"},
    {'k', "-.-"},
    {'l', ".-.."},
    {'m', "--"},
    {'n', "-."},
    {'o', "---"},
    {'p', ".--."},
    {'q', "--.-"},
    {'r', ".-."},
    {'s', "..."},
    {'t', "-"},
    {'u', "..-"},
    {'v', "...-"},
    {'w', ".--"},
    {'x', "-..-"},
    {'y', "-.--"},
    {'z', "--.."},
};

int pairsCount = translators.size();


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

    cout << "Your text:\n";
    cout << text << "\n\n";

    for (int i = 0; text[i] != '\0'; i++) {
        if (i != 0) morse += ' ';

        morse += toMorse(text[i]);
    }

    cout << "Morse translation:\n";
    cout << morse << "\n\n";

    return 0;
}

string toMorse(char c)
{
    for (int i = 0; i < pairsCount; i++) {
        Translator t = translators[i];

        if (tolower(c) == t.letter) {
            return t.morse;
        }
    }

    return "?";
}

