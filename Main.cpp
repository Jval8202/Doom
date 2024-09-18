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
float fDepth = 16.0f;

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

            float fEyeX = sinf(fRayAngle); //Unit vector for ray in player space
            float fEyeY = cosf(fRayAngle);
            
            while(!bHitWall && fDistanceToWall < fDepth){

                fDistanceToWall += 0.1f;
                int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
                int nTestY = (int)(fPlayerY+ fEyeY * fDistanceToWall);

                if(nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight){

                    bHitWall = true;
                    fDistanceToWall = fDepth;
                }
                else
                {  
                    //Ray is inbounds so test to see if the ray cell is a wall block
                    //if we hit something in the map with the # symbol, then we hit a wall, if not, 
                    //then we did not hit a wall
                    if(map[nTestY * nMapWidth + nTestX] == '#'){
                            
                        bHitWall = true;

                    }
                }

            }
            
            //calculating the distance between ceiling and floor
            int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
            int nFloor = nScreenHeight - nCeiling;
            
        }
        
        screen[nScreenWidth * nScreenHeight - 1] = '\0'; ///This sets the very the last character 
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, {0,0}, &dwBytesWritten);
        ///This prevents the console to scroll down when it is outputing the text

    }



    return 0;

}
