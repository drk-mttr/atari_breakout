#include "olcPixelGameEngine.h"

class BreakOut : public olc::PixelGameEngine {
public:
    BreakOut(); // default constructor
    bool OnUserCreate() override; // called once at the start of program
    bool OnUserUpdate(float fElapsedTime) override; // called once every frame
private:
    float fBatPos = 20.0f;
    float fBatWidth = 40.0f;
    float fBatSpeed = 15.0f;
    olc::vf2d vBallPos = {0.0f, 0.0f}; // ball position
    olc::vf2d vBallDir = {0.0f, 0.0f}; // ball direction
    float fBallSpeed = 10.0f; // ball direction
    float fBallRadius = 5.0f; // ball radius

    olc::vi2d vBlockSize = {16, 16}; // pixels in each tile (16x16 pixels)
    int iHorizontalTiles = 12; // horizontal tiles
    int iVerticalTiles = 15; // vertical tiles
    std::unique_ptr<int[]> blocks; // number of blocks on the screen (i.e. our tile array)

    std::unique_ptr<olc::Sprite> sprTile; // tile sprite
};