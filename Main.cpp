#include <iostream>

using namespace std;

#include <Windows.h>

int nScreenWidth = 120;
int nScreenHeight = 40;

///character block
float fPlayerX = 0.0f;
float fPlayerY = 0.0f;
float fPlayerA = 0.0f;

///Constants for the map
int nMapHeight = 16;
int nMapWidth = 16;

float fFOV = 3.14159 / 4;

int main(){

///creates the screen buffer

    wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    wstring map;
    
    map += L"################";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"################";
    
    while(1)
    {///Main loop for the videogame 

        for(int x = 0; x < nScreenWidth; x++){

            float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;
            
            float fDistanceToWall = 0;
            bool bHitWall = false;
            
            while(!bHitWall){
                

                fDistanceToWall += 0.1f;
            }
            
        }
        
        screen[nScreenWidth * nScreenHeight - 1] = '\0'; ///This sets the very the last character 
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, {0,0}, &dwBytesWritten);
        ///This prevents the console to scroll down when it is outputing the text

    }



    return 0;

}
