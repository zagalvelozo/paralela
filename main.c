/**
 * Printing Args - A Simple C Program
 *
 * @package  Printing Args
 * @author   Jesus Zagal <zagalvelozo@gmail.com>
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++) {
        printf("%i %s \n", i, argv[i]);    
    }
    return 0;
}
