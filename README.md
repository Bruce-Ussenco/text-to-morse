# Text to Morse
A simple c++ command line program that translates text into morse code.

## Build program

First clone this repo.
```bash
git clone https://github.com/Bruce-Ussenco/text-to-morse.git
```

And compile using g++.
```bash
cd text-to-morse
g++ to_morse.cpp -o to_morse
```

## Run program

Run the executable with a text as argument inside quotation marks.
```bash
./to_morse "This text will be translated into morse code!"
```

Output:
```bash

Your text:
"This text will be translated into morse code!"

Morse translation:
"- .... .. ...   - . -..- -   .-- .. .-.. .-..   -... .   - .-. .- -. ... .-.. .- - . -..   .. -. - ---   -- --- .-. ... .   -.-. --- -.. . ?"
```

? = translation not found.

