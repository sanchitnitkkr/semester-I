// Write a program to find the number of vowels, consonants, digits and white spaces

#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum ASCII
{
    // --- Vowels ---
    A = 65,
    E = 69,
    I = 73,
    O = 79,
    U = 85,
    a = 97,
    e = 101,
    i = 105,
    o = 111,
    u = 117,

    // --- Consonants (Uppercase) ---
    B = 66,
    C = 67,
    D = 68,
    F = 70,
    G = 71,
    H = 72,
    J = 74,
    K = 75,
    L = 76,
    M = 77,
    N = 78,
    P = 80,
    Q = 81,
    R = 82,
    S = 83,
    T = 84,
    V = 86,
    W = 87,
    X = 88,
    Y = 89,
    Z = 90,

    // --- Consonants (Lowercase) ---
    b = 98,
    c = 99,
    d = 100,
    f = 102,
    g = 103,
    h = 104,
    j = 106,
    k = 107,
    l = 108,
    m = 109,
    n = 110,
    p = 112,
    q = 113,
    r = 114,
    s = 115,
    t = 116,
    v = 118,
    w = 119,
    x = 120,
    y = 121,
    z = 122,

    // --- Digits ---
    ZERO = 48,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE, // 48–57

    // --- Whitespace characters ---
    SPACE = 32,
    TAB = 9,
    NEWLINE = 10,
    CARRIAGE_RETURN = 13
};

/**
 * Simply returns the LOWERCASED ASCII value of a character
 * @param char character The character
 * @return void
 */
int getAsciiValue(char character)
{
    return (int)tolower(character);
}

/**
 * Helper function for printSentenceStats()
 * Modifies the existing array based upon the ASCII value.
 * The index values are locked ie:
 * Others => Index 4
 * Whitespace => Index 3
 * Digits => Index 2
 * Vowels => Index 1
 * Consonants => Index 0
 * @param int result[] The array to be modified
 * @param int The ascii value using which the result will be modified
 * @return void
 */
void updateResultByAsciiValue(int result[], int asciiValue)
{
    // Space character
    if (asciiValue == SPACE)
    {
        result[3] += 1;
    }
    else if (asciiValue >= ZERO && asciiValue <= NINE)
    {
        result[2] += 1;
    }
    else if (asciiValue == a || asciiValue == e || asciiValue == i || asciiValue == o || asciiValue == u)
    {
        result[0] += 1;
    }
    else if (asciiValue >= a && asciiValue <= z)
    {
        result[1] += 1;
    }
    else
    {
        result[4] += 1;
    }
}

/**
 * Prints the summary ie vowels, consonants, digits (numbers) and whitespaces
 *
 * @param char sentence[] The string you have
 * @param int The size of the string
 * @return void
 */

void printSentenceStats(char sentence[], int size)
{
    int result[5] = {0, 0, 0, 0, 0}; // An array which stores the values required for vowels, consonants, digits and whitespaces respectively

    for (int i = 0; i < size; i++)
    {
        int asciiValue = getAsciiValue(sentence[i]);
        updateResultByAsciiValue(result, asciiValue);
    }

    printf("\n===SUMMARY===\n");
    printf("Vowel Count => %d\n", result[0]);
    printf("Consonants Count => %d\n", result[1]);
    printf("Digits Count => %d\n", result[2]);
    printf("Whitespaces Count => %d\n", result[3]);
}

int main()
{
    char sentence[] = "";
    printf("Enter the sentence please: ");
    scanf("%199[^\n]", sentence); //   fgets(sentence, sizeof(sentence), stdin);  // read with spaces => This could had been used which is more recommended since it handles buffer overflow and whitespaces both.
    printSentenceStats(sentence, strlen(sentence));
}