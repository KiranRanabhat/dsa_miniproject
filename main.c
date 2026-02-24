#include "raylib.h"
#include "stack.h"
#include "ui.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Stack Visualizer (C + Raylib)");
    SetTargetFPS(60);

    Stack stack;
    InitStack(&stack);

    int inputValue = 0;
    char message[100] = "Enter value and click Push";

    Rectangle pushBtn = {500, 150, 150, 50};
    Rectangle popBtn = {500, 230, 150, 50};
    Rectangle resetBtn = {500, 310, 150, 50};

    while (!WindowShouldClose()) {

        // Keyboard input (0-9 keys)
        if (IsKeyPressed(KEY_ZERO)) inputValue = 0;
        if (IsKeyPressed(KEY_ONE)) inputValue = 1;
        if (IsKeyPressed(KEY_TWO)) inputValue = 2;
        if (IsKeyPressed(KEY_THREE)) inputValue = 3;
        if (IsKeyPressed(KEY_FOUR)) inputValue = 4;
        if (IsKeyPressed(KEY_FIVE)) inputValue = 5;
        if (IsKeyPressed(KEY_SIX)) inputValue = 6;
        if (IsKeyPressed(KEY_SEVEN)) inputValue = 7;
        if (IsKeyPressed(KEY_EIGHT)) inputValue = 8;
        if (IsKeyPressed(KEY_NINE)) inputValue = 9;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw Stack Visualization
        DrawStack(&stack);

        // Show input value
        DrawText("Press number key (0-9):", 480, 80, 20, BLACK);
        char inputText[50];
        sprintf(inputText, "Input Value: %d", inputValue);
        DrawText(inputText, 500, 110, 20, DARKGREEN);

        // Push Button
        if (Button(pushBtn, "PUSH")) {
            if (!IsFull(&stack)) {
                Push(&stack, inputValue);
                sprintf(message, "Pushed %d to stack", inputValue);
            } else {
                sprintf(message, "Stack Overflow!");
            }
        }

        // Pop Button
        if (Button(popBtn, "POP")) {
            if (!IsEmpty(&stack)) {
                int topVal = Peek(&stack);
                Pop(&stack);
                sprintf(message, "Popped %d from stack", topVal);
            } else {
                sprintf(message, "Stack Underflow!");
            }
        }

        // Reset Button
        if (Button(resetBtn, "RESET")) {
            InitStack(&stack);
            sprintf(message, "Stack Reset");
        }

        // Display Top Element
        if (!IsEmpty(&stack)) {
            char topText[50];
            sprintf(topText, "Top Element: %d", Peek(&stack));
            DrawText(topText, 480, 400, 20, MAROON);
        } else {
            DrawText("Top Element: None", 480, 400, 20, MAROON);
        }

        // Message display
        DrawText(message, 400, 500, 20, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}