#include <stdio.h>
#include <raylib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));

    int width = 800;
    int height = 600;
    int scale = 10;
    float x = 400;
    float y = 300;
    float Xvel = rand() % 61;
    float Yvel = rand() % 61;
    int Tvel = 100; // terminal velocity
    float loss = 0.87; // how much vel is lost upon hitting a wall: velocity * loss
    int i = 0;
    
    InitWindow(width, height, "Window");

    while (!WindowShouldClose()) {

        BeginDrawing();

        if (y + scale + Yvel >= height - scale) {
            y = height - scale;
            Yvel = -Yvel * loss;
            Xvel = Xvel * loss;

        } else if ((y + Yvel) <= 0) {
            y = 0;
            Yvel = -Yvel * loss;

        } else if (Yvel < Tvel) {
            Yvel++;
        }

        if (fabsf(Yvel) < 1 && y + scale >= height - scale) {
            Yvel = 0;
            y = height - scale*2;
        }

        if ((x + Xvel) >= width-scale) { //update x vel
            Xvel = -Xvel * loss;

        } else if ((x + Xvel) <= 0) {
            Xvel = -Xvel * loss;
        }

        if (Yvel <= 0.001 && Yvel >= -0.001 && Xvel <= 0.05 && Xvel >= -0.05) {
            Xvel = rand() % 61;
            Yvel = rand() % 61;
        }

        x += Xvel;
        y += Yvel;

        ClearBackground(BLACK);
        DrawRectangle(0, height-scale, width, scale, WHITE); // floor
        DrawRectangle((int)x, (int)y, scale, scale, WHITE); //square

        printf("XVEL: %.6f | YVEL: %.6f\n", Xvel, Yvel);
        
        EndDrawing();
        usleep(20000);
        i++;
    }

    CloseWindow();

    return 0;
}