#include "breakout.h"

BreakOut::BreakOut() {
    sAppName = "TUTORIAL - Breakout clone";
}

bool BreakOut::OnUserCreate() {

    // initialise number blocks
    blocks = std::make_unique<int[]>(iHorizontalTiles * iVerticalTiles);
    for (int y = 0; y < iVerticalTiles; y++) {
        for (int x = 0; x < iHorizontalTiles; x++) {
            // set values for boundaries and objects
            if (x == 0 || y == 0 || x == (iHorizontalTiles - 1))
                blocks[y * iHorizontalTiles + x] = 10; // set value at the left, top and right screen blocks to 10
            else
                blocks[y * iHorizontalTiles + x] = 0; // set value of all other blocks to 0

            if (x > 2 && x <= 8 && y > 2 && y <= 3)
                blocks[y * iHorizontalTiles + x] = 1; // set value of last block row to 1
            if (x > 2 && x <= 8 && y > 3 && y <= 4)
                blocks[y * iHorizontalTiles + x] = 2; // set value of middle block row to 2
            if (x > 2 && x <= 8 && y > 4 && y <= 5)
                blocks[y * iHorizontalTiles + x] = 3; // set value of first block row to 3
        }
    }

    // Load the sprite (PNGs are placed in a gfx folder and referred to from a relative path to the binary executable)
    sprTile = std::make_unique<olc::Sprite>("../gfx/tut_tiles.png");

    return true;
}

bool BreakOut::OnUserUpdate(float fElapsedTime) {

    // calculate the potential position of the ball if there are no collisions
    olc::vf2d vPotentialBallPos = vBallPos + vBallDir * fBallSpeed * fElapsedTime;

    // calculate the radial dimensions of the ball in world space
    olc::vf2d vTileBallRadialDims = { fBallRadius / vBlockSize.x, fBallRadius / vBlockSize.y };

    // 
    auto TestResolveCollisionPoint = [&](const olc::vf2d& point) {

    };


    // Clear Screen background every frame
    Clear(olc::DARK_BLUE);
    SetPixelMode(olc::Pixel::MASK);

    // Draw outer bounds
    for (int y = 0; y < iVerticalTiles; y++) {
        for (int x = 0; x < iHorizontalTiles; x++) {
            switch (blocks[y * iHorizontalTiles + x]) {
                case 0: // Do Nothing
                    break;
                case 10: // Draw Boundry
                    DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(0, 0) * vBlockSize, vBlockSize);
                    break;
                case 1: // Draw Red Block
                    DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(1, 0) * vBlockSize, vBlockSize);
                    break;
                case 2: // Draw Green Block
                    DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(2, 0) * vBlockSize, vBlockSize);
                    break;
                case 3: // Draw Yellow Block
                    DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(3, 0) * vBlockSize, vBlockSize);
                    break;

            }
        }
    }
    SetPixelMode(olc::Pixel::NORMAL);

    // Move bat
    

    return true;
}