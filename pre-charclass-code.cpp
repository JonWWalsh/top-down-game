// #include "raylib.h"
// #include "raymath.h"

// class character
// {
// public:
//     Vector2 getWorldPos() { return worldPos; }      // Small functions can be condensed to 1 line ***Getters do not have a ; at the end of the functiton.
//     void setScreenPos(int winWidth, int winHeight); // To add a function outside of the class that would normally be in it, add a ; to the end of the function.  Cont on ln25.
//     void tick(float deltaTime);

// private:
//     Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
//     Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
//     Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
//     Vector2 screenPos;
//     Vector2 worldPos;
//     // 1 : facing right, -1 : facing left
//     float rightLeft{1.f};
//     // animation variables
//     float runningTime{};
//     int frame{};
//     const int maxFrames{6};
//     const float updateTime{1.f / 12.f};
//     const float speed{4.f};
// };
// // You must tell the compiler which class the function belongs to using "classname"::  The :: is known as the 'scope resolution operator.'
// void character::setScreenPos(int winWidth, int winHeight) // function will initalize screenPos to the correct value using the window dimensions.
// {
//     screenPos = {
//         (float)winWidth / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
//         (float)winHeight / 2.0f - 4.0f * (0.5f * (float)texture.height)};
// }

// void character::tick(float deltaTime)
// {
//     Vector2 direction{};
//     if (IsKeyDown(KEY_A))
//         direction.x -= 1.0; // If the code that would be in {} is 1 line, the code can just be added at the end of the if statement.
//     if (IsKeyDown(KEY_D))
//         direction.x += 1.0;
//     if (IsKeyDown(KEY_W))
//         direction.y -= 1.0;
//     if (IsKeyDown(KEY_S))
//         direction.y += 1.0;
//     // If direction is 0 we don't need to move.  Vector2Length takes a vector and returns a float representing how long the vector is.  We move if it isn't = to 0.0.
//     if (Vector2Length(direction) != 0.0) // lets us determine if vector has magnitude of 0 to decide whether to use idle or run animation.
//     {

//         // set worldPos = worldPos + direction
//         // Vector2Normalize(direction) is used to keep diagonal movement the same speed as cardinal direction speed.
//         worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed)); // takes the quantity of 2nd element and subtracts from mapPos
//         direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;                            // tunary operator can be used in place of single line if/else statments
//         texture = run;
//     }
//     else
//     {
//         texture = idle;
//     }
//     // update animation frame
//     runningTime += deltaTime; // since dT is already being called into the function GetFrameTime() can be replaced with deltaTime.
//     if (runningTime >= updateTime)
//     {
//         frame++;
//         runningTime = 0.f;
//         if (frame > maxFrames)
//             frame = 0;
//     }
//     // draw the character
//     Rectangle source{frame * (float)texture.width / 6.f, 0.f, rightLeft * (float)texture.width / 6.f, (float)texture.height}; // using first frame in animation(0.f, 0.f) then knight height and width
//     Rectangle dest{screenPos.x, screenPos.y, 4.0f * (float)texture.width / 6.0f, 4.0f * (float)texture.height};              // where we wish to draw the knight in the window.  in width/height, this is where we scale
//     DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
// }

// int main()
// {
//     const int windowWidth{384};
//     const int windowHeight{384};
//     InitWindow(windowWidth, windowHeight, "Jon's Top-down Game");

//     Texture2D worldMap = LoadTexture("nature_tileset/WorldMap.png");
//     Vector2 mapPos{0.0, 0.0};
//     float speed{4.0}; // Used to scale map scroll speed.

//     Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
//     Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
//     Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
//     Vector2 knightPos{
//         // loc on screen for knight's upper-left corner
//         // draw knight to center of screen.  Placing the f behind a # turns it into a float.
//         (float)windowWidth / 2.0f - 4.0f * (0.5f * (float)knight.width / 6.0f), // Due to the size of spritesheet, we scale the img by a factor of 4.0f.
//         (float)windowHeight / 2.0f - 4.0f * (0.5f * (float)knight.height)       // (float) takes the value to the right and turns it into a float, this is know as a C-style cast.
//     };
//     // 1 : facing right, -1 : facing left
//     float rightLeft{1.f};
//     // animation variables
//     float runningTime{};
//     int frame{};
//     const int maxFrames{6};
//     const float updateTime{1.f / 12.f};

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//         ClearBackground(WHITE);

//         Vector2 direction{};
//         if (IsKeyDown(KEY_A))
//             direction.x -= 1.0; // If the code that would be in {} is 1 line, the code can just be added at the end of the if statement.
//         if (IsKeyDown(KEY_D))
//             direction.x += 1.0;
//         if (IsKeyDown(KEY_W))
//             direction.y -= 1.0;
//         if (IsKeyDown(KEY_S))
//             direction.y += 1.0;
//         // If direction is 0 we don't need to move.  Vector2Length takes a vector and returns a float representing how long the vector is.  We move if it isn't = to 0.0.
//         if (Vector2Length(direction) != 0.0) // lets us determine if vector has magnitude of 0 to decide whether to use idle or run animation.
//         {

//             // set mapPos = mapPos - direction
//             // Vector2Normalize(direction) is used to keep diagonal movement the same speed as cardinal direction speed.
//             mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed)); // takes the quantity of 2nd element and subtracts from mapPos
//             direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;                             // tunary operator can be used in place of single line if/else statments
//             knight = knight_run;
//         }
//         else
//         {
//             knight = knight_idle;
//         }
//         // draw the map
//         DrawTextureEx(worldMap, mapPos, 0.0, 4.0, WHITE);

//         // update animation frame
//         runningTime += GetFrameTime(); // GetFrameTime = delta time
//         if (runningTime >= updateTime)
//         {
//             frame++;
//             runningTime = 0.f;
//             if (frame > maxFrames)
//                 frame = 0;
//         }

//         // draw the character
//         Rectangle source{frame * (float)knight.width / 6.f, 0.f, rightLeft * (float)knight.width / 6.f, (float)knight.height}; // using first frame in animation(0.f, 0.f) then knight height and width
//         Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width / 6.0f, 4.0f * (float)knight.height};              // where we wish to draw the knight in the window.  in width/height, this is where we scale
//         DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

//         EndDrawing();
//     }
//     CloseWindow();
//     UnloadTexture(worldMap);
//     UnloadTexture(knight);
//     UnloadTexture(knight_idle);
//     UnloadTexture(knight_run);
// }