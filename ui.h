#ifndef UI_H
#define UI_H

#include "raylib.h"
#include "stack.h"

void DrawStack(Stack *s);
bool Button(Rectangle rect, const char *text);

#endif