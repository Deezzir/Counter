#include <iostream>

#include "raylib.h"

#define FACTOR 30
#define LOGO_FILEPATH "./favicon.png"

#define COLOR_BACKGROUND GetColor(0x000015FF)
#define FONT_SIZE 100

#define DECREMENT_KEY KEY_DOWN
#define DECREMENT_KEY_ALT KEY_BACKSPACE
#define INCREMENT_KEY KEY_UP
#define INCREMENT_KEY_ALT KEY_SPACE
#define RESET_KEY KEY_R

class Counter {
   private:
    unsigned int count;

   public:
    Counter() : count(0) {}
    Counter(int count) : count(count) {}

    int getCount() { return count; }
    void setCount(int count) { this->count = count; }

    void increment() { count++; }
    void decrement() { if (count > 0) count--; }
    void reset() { count = 0; }
};

int main() {
    Image logo = LoadImage(LOGO_FILEPATH);

    InitWindow(FACTOR * 16, FACTOR * 9, "Counter");
    SetTargetFPS(60);
    SetWindowIcon(logo);

    Counter counter;

    while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE) && !IsKeyPressed(KEY_Q)) {
        int w = GetRenderWidth();
        int h = GetRenderHeight();

        if (IsKeyPressed(INCREMENT_KEY) || IsKeyPressed(INCREMENT_KEY_ALT)) {
            counter.increment();
        }

        if (IsKeyPressed(DECREMENT_KEY) || IsKeyPressed(DECREMENT_KEY_ALT)) {
            counter.decrement();
        }

        if (IsKeyPressed(RESET_KEY)) {
            counter.reset();
        }

        BeginDrawing();
        {
            ClearBackground(COLOR_BACKGROUND);

            std::string msg = std::to_string(counter.getCount());
            int text_width = MeasureText(msg.c_str(), FONT_SIZE);
            DrawText(msg.c_str(), w / 2 - text_width / 2, h / 2 - FONT_SIZE / 2, FONT_SIZE, WHITE);
        }
        EndDrawing();
    }

    CloseWindow();
    UnloadImage(logo);
    return 0;
}