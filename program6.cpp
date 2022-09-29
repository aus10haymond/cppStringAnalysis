// Austen Haymond
// Program to take in a string as an array of characters
//count how many times each character is used, and display usage rate 

#include <iostream>
using namespace std;
#include <math.h>

void getLine(char text[]);
int charCount(char text[], int lCount[]);
char toLower(char letter);
void printTable(int lCount[], int count);
void getFrequency(int lCount[], char &letter, int &max, int count, float &freq);

int main() {
    int count, max;
    float freq;
    int lCount[26];
    char text[1001];
    char letter, cont;

    cout << "================================" << endl
         << "=======Character Frequency======" << endl
         << "============Counter=============" << endl
         << "================================" << endl;

    do {
        cout << endl << "Enter the text you would like to analyze: ";

        getLine(text);
        count = charCount(text, lCount);
        getFrequency(lCount, letter, max, count, freq);

        cout << "Total Characters: " << count << endl;
        cout << "Most Frequent Character: " << letter << " | Count: " << max 
        << " | Frequency: " << (float) freq * 100 << "%" << endl << endl;

        printTable(lCount, count);

        cout << "Would you like to analyze more text? (y/n)" << endl;
        while (cont != 'y' && cont != 'n') {
            cin >> cont;
            if (cont != 'y' && cont != 'n') {
                cout << "Please enter 'y' or 'n': ";
            }
        }
    }

    while( cont != 'n');

    return 0;
}

void getLine(char text[]) {
    int ix = 0;
    char c;

    c = cin.get();
    while (c != '\n') {
        text[ix] = c;
        ++ix;
        c = cin.get();
    }
    text[ix] = '\0';
}

int charCount(char text[], int lCount[]) {
    int count = 0;

    for (int iy = 0; iy < 26; iy++) {
        lCount[iy] = 0;
    }

    for (int ix = 0; text[ix] != '\0'; ix++) {
        if (text[ix] != ' ') {
            if ((int) text[ix] < 'a') {
                text[ix] = toLower(text[ix]);
            }
            int cCount = (int) (text[ix] - 'a');
            ++count;
            ++lCount[cCount];
        }
        else {
            count += 0;
        }
    }

    return count;
}

char toLower(char letter) {
    char lower;
    if ((int) letter < 'a') {
        lower = (char) (letter + 32);
    }
    else {
        lower = letter;
    }
    return lower;
}

void printTable(int lCount[], int count) {
    char letter, pause;
    float frequency;

    cout << "Letter | Count | Frequency" << endl;
    cout << "-------+-------+----------" << endl;

    for (int ix = 0; ix < 13; ix++) {
        letter = (char) ('a' + ix);
        frequency = (float) (100 * lCount[ix] / count);
        cout << "    " << letter << "  |  " << lCount[ix] << "   |  " 
        << frequency << "%" << endl;
    }

    cout << "Press any key to continue:" << endl;
    cin >> pause;

    cout << "Letter | Count | Frequency" << endl;
    cout << "-------+-------+----------" << endl;

    for (int iy = 13; iy < 26; iy++) {
        letter = (char) ('a' + iy);
        frequency = (float) (100 * lCount[iy] / count);
        cout << "    " << letter << "  |  " << lCount[iy] << "   |  " 
        << frequency << "%" << endl;
    }
}

void getFrequency(int lCount[], char &letter, int &max, int count, float &freq) {
    max = 0;
    for (int ix = 0; ix < 26; ix++) {
        if (lCount[ix] > max) {
            max = lCount[ix];
            freq = (float) max / count;
            letter = (char) ('a' + ix);
        }
        else {
            max = max;
        }
        
    }
}