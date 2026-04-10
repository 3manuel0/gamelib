#include"include/raylib.h"

#define screenWidth 1280
#define screenHeight 720

static Rectangle rect = {50, 50, 200, 200};
static Rectangle rect2 = {200, 100, 200, 200};
static Vector2 velocity = {200, 200};
static Vector2 velocity2 = {150, 150};



// perfect velocity
// static Vector2 velocity = {800, 800};

void GameInit(){
    InitWindow(screenWidth, screenHeight, "testing raylib in web");
    SetTargetFPS(60);
}


void GameFrame(){
    BeginDrawing();
    ClearBackground((Color){0xcd, 0xd6, 0xf4, 0xff});
    float dt = GetFrameTime();
    if((rect.x < 0 && velocity.x < 0)|| (rect.x  + rect.width >= GetScreenWidth() && velocity.x > 0 )){
        velocity.x *= -1;
    }
    if((rect.y < 0 && velocity.y < 0) || (rect.y  + rect.height >= GetScreenHeight() && velocity.y > 0)){
        velocity.y *= -1;
    }
    rect.y += velocity.y*dt;
    rect.x += velocity.x*dt;
    if((rect2.x < 0 && velocity2.x < 0)|| (rect2.x  + rect2.width >= GetScreenWidth() && velocity2.x > 0 )){
        velocity2.x *= -1;
    }
    if((rect2.y < 0 && velocity2.y < 0) || (rect2.y  + rect2.height >= GetScreenHeight() && velocity2.y > 0)){
        velocity2.y *= -1;
    }
    rect2.y += velocity2.y*dt;
    rect2.x += velocity2.x*dt;
    DrawRectangleRec(rect2, ORANGE);
    DrawText("This is just a test for this library", 0, 0, 24, BLACK);
    DrawFPS(screenWidth - 90 , 0);
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, DARKBLUE);
    EndDrawing();
}


#ifndef PLATFORM_WEB
#include <stdio.h>
int main(){
    GameInit();
    // Main game loop
    while (!WindowShouldClose())
    {   

        GameFrame();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
#endif