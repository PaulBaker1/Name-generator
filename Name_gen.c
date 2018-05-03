#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


char NamePrefix[][5] =
{
    "","nar","xan","bell","natr","ev"
};
char NameSuffix[][5] =
{
    "", "us", "ix", "ox", "ith",
    "ath", "um", "ator", "or", "axia",
    "imus", "ais", "itur", "orex", "o",
    "y"
};

const char NameStems[][10] =
{
    "adur", "aes", "anim", "apoll", "imac",
    "educ", "equis", "extr", "guius", "hann",
    "equi", "amora", "hum", "iace", "ille",
    "inept", "iuv", "obe", "ocul", "orbis"
};

void NameGen(char *PlayerName);
char get_char(void);

int main()
{
    char Player1Name[21];
    char con;
    srand((long)time(NULL));
    do
    {
        NameGen(Player1Name);
        printf("Generated Name: %s\n\n",Player1Name);
        puts("Would you like to generate another name(Y,N):");
        con = get_char();
    }
    while (con !='n' && con !='N');
    return 0;
}
char get_char(void)
{
    char con;
    while((con = getchar())<27);
    return con;
}

void NameGen(char* PlayerName)
{
    PlayerName[0]=0;
    strcat(PlayerName, NamePrefix[(rand() % 7)]);

    strcat(PlayerName, NameStems[(rand() % 20)]);

    strcat(PlayerName, NameSuffix[(rand() % 16)]);

    PlayerName[0]=toupper(PlayerName[0]);
    return;
}
