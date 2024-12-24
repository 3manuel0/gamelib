#include"raylib.h"

void GameInit(){
    InitWindow(1280, 720, "testing raylib in web");
    SetTargetFPS(60);
}

static Rectangle rect = {50, 50, 200, 200};
static Vector2 velocity = {200, 200};

void GameFrame(){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    float dt = GetFrameTime();
    float x =  rect.x + velocity.x*dt;
    if((rect.x < 0 && velocity.x < 0)|| (rect.x  + rect.width >= GetScreenWidth() && velocity.x > 0 )){
        velocity.x *= -1;
    }
    rect.x = x;
    float y =  rect.y + velocity.y*dt;
    if((rect.y < 0 && velocity.y < 0) || (rect.y  + rect.height >= GetScreenHeight() && velocity.y > 0)){
        velocity.y *= -1;
    }
    rect.y  = y;
    // DrawRectangleRec(rect, BLACK);
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, DARKBLUE);
    EndDrawing();
}
void print(char * a);



    // MyStruct t = (MyStruct){10, 20.5};
    // addStruct(t);
    // print("The universe breaks everyone");
    // GameInit();
    // GameFrame();

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