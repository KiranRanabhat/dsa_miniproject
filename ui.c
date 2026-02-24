#include "ui.h"
#include <stdio.h>

void DrawStack(Stack *s) {
    int baseX = 220;
    int baseY = 520;
    int width = 100;
    int height = 40;
    int gap = 45;

    // Title (Top - clean)
    DrawText("STACK VISUALIZER", 240, 20, 30, DARKBLUE);

    // Stack container boundary
    DrawRectangleLines(baseX, baseY - (10 * gap), width, 10 * gap, BLACK);

    // Draw stack elements
    for (int i = 0; i <= s->top; i++) {
        int y = baseY - ((i + 1) * gap);

        // Highlight top element
        if (i == s->top) {
            DrawRectangle(baseX, y, width, height, ORANGE);
        } else {
            DrawRectangle(baseX, y, width, height, SKYBLUE);
        }

        char value[10];
        sprintf(value, "%d", s->data[i]);
        DrawText(value, baseX + 40, y + 10, 20, BLACK);
    }

    // TOP Pointer (ASCII arrow - no ? issue)
    if (s->top != -1) {
        int topY = baseY - ((s->top + 1) * gap);
        DrawText("TOP ->", baseX - 100, topY + 10, 22, MAROON);
        DrawLine(baseX - 30, topY + 20, baseX, topY + 20, MAROON);
    }

    // 🔥 Stack Size BELOW container (uses empty space perfectly)
    char sizeText[50];
    sprintf(sizeText, "Stack Size: %d / 10", s->top + 1);
    DrawText(sizeText, 200, 560, 25, DARKBLUE);
}
    

bool Button(Rectangle rect, const char *text) {
    Vector2 mouse = GetMousePosition();
    bool clicked = false;

    if (CheckCollisionPointRec(mouse, rect)) {
        DrawRectangleRec(rect, LIGHTGRAY);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            clicked = true;
        }
    } else {
        DrawRectangleRec(rect, GRAY);
    }

    int textWidth = MeasureText(text, 20);
    DrawText(text, rect.x + (rect.width - textWidth)/2, rect.y + 10, 20, BLACK);

    return clicked;
}