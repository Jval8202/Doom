#include <iostream>

using namespace std;

#include <Windows.h>

int nScreenWidth = 120;
int nScreenHeight = 40;

///character block
float fPlayerX = 0.0f;
float fPlayerY = 0.0f;

int main(){

///creates the screen buffer

    wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    while(1)
    {///Main loop for the videogame 


        screen[nScreenWidth * nScreenHeight - 1] = '\0'; ///This sets the very the last character 
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, {0,0}, &dwBytesWritten);
        ///This prevents the console to scroll down when it is outputing the text

    }



    return 0;

}
