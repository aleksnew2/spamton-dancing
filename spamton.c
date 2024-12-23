#include "raylib.h"

#define MAX_FRAME_DELAY 20
#define MIN_FRAME_DELAY 1

int main(void) {
    const int screenWidth  = 500;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Spamton Dancing");

    int   animFrames = 0;
    Image imSpamtonAnim =
        LoadImageAnim("spamton-spamton-dance.gif", &animFrames);

    Texture2D texSpamtonAnim = LoadTextureFromImage(imSpamtonAnim);

    unsigned int nextFrameDataOffset = 0;

    int currentAnimFrame = 0;
    int frameDelay       = 8;
    int frameCounter     = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        frameCounter++;
        if (frameCounter >= frameDelay) {
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames) currentAnimFrame = 0;

            nextFrameDataOffset = imSpamtonAnim.width * imSpamtonAnim.height *
                                  4 * currentAnimFrame;

            UpdateTexture(
                texSpamtonAnim,
                ((unsigned char *)imSpamtonAnim.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(texSpamtonAnim,
                    GetScreenWidth() / 2 - texSpamtonAnim.width / 2, 0,
                    WHITE);

        EndDrawing();
    }

    UnloadTexture(texSpamtonAnim);
    UnloadImage(imSpamtonAnim);

    CloseWindow();

    return 0;
}
