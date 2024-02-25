#include <iostream>
#include <string>
#include <vector>

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

int translatorsCount = translators.size();


string toMorse(char c);
bool checkErrors(int argc);

int main(int argc, char **argv)
{
    cout << '\n';

    if (checkErrors(argc)) return 1;

    // the text to translate is the first arg
    char *text = argv[1];
    string morse = "";

    cout << "Your text:\n";
    cout << '\"' << text << "\"\n\n";

    // find the translation of each char
    for (int i = 0; text[i] != '\0'; i++) {
        if (i != 0) morse += ' ';

        morse += toMorse(text[i]);
    }

    cout << "Morse translation:\n";
    cout << '\"' << morse << "\"\n\n";

    return 0;
}

string toMorse(char c)
{
    for (int i = 0; i < translatorsCount; i++) {
        Translator t = translators[i];

        if (tolower(c) == t.letter) {
            return t.morse;
        }
    }

    return "?";
}

bool checkErrors(int argc)
{
    if (argc == 1) {
        cout << "[ERROR] Pass some text!\n\n";
        
        return true;
    }

    if (argc > 2) {
        cout << "[ERROR] Pass a single argument\n"
             << "To do that, place your text inside \"\":\n"
             << "to_morse \"all the text you want to translate into morse code\"\n\n";

        return true;
    }

    return false;
}

