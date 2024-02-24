#include <iostream>

int main(int argc, char **argv)
{
    std::cout << '\n' << argc << '\n';

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << '\n';
    }

    std::cout << '\n';

    return 0;
}

