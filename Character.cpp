#include "Character.h"
#include "raymath.h"


Character::Character(int winWidth, int winHeight) :
    windowWidth(winWidth),
    windowHeight(winHeight) //Now storing winWidth/height as state instead of as screenPos.
{ // screenPos takes the windowWidth and windowHeight and / 2.  You then need to move up and to the left by half the width&height of our sprite.  Then scale by 4 since the texture is scaled by 4.
    width = texture.width / maxFrames;
    height = texture.height;
    // static_cast is a C++ function that prevents you from casting incompatible types.  The value we wish to cast goes in the (), in the <> goes the type we wish to cast to.
    // screenPos = {static_cast<float>(winWidth) / 2.0f - scale * (0.5f * width),
    //     static_cast<float>(winHeight) / 2.0f - scale * (0.5f * height)
    // };

}

Vector2 Character::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)
    };
} 



// void Character::setScreenPos(int winWidth, int winHeight) // function will initalize screenPos to the correct value using the window dimensions.
// {
//     screenPos = {
//         (float)winWidth / 2.0f - 4.0f * (0.5f * width),
//         (float)winHeight / 2.0f - 4.0f * (0.5f * height)};
// }

void Character::tick(float deltaTime)
{
    if (!getAlive()) return; //checks to see if player is alive at start, if not then code stops here.
    // Vector2 direction{};
    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0; // If the code that would be in {} is 1 line, the code can just be added at the end of the if statement.
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;
    BaseCharacter::tick(deltaTime);  //This gets moved  behind key inputs since we are using velocity to update worldPos in BaseCharacter, so we should call BaseChar's tick function after we update velocity.  BaseCharacter now uses velocity, then zeroes it out.
    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if (rightLeft > 0.f) // Sets sword location on character and offsets for right/left facing.
    {
        origin = {0.f, weapon.height * scale};
        offset = {35.f, 55.f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale
        };
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.f : 0.f; // sets rotation to trigger on left mouseclick
    }
    else{
        origin = {weapon.width * scale, weapon.height * scale};
        offset = {25.f, 55.f};
            weaponCollisionRec = {
            getScreenPos().x + offset.x - weapon.width * scale,
            getScreenPos().y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale
        };
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35.f : 0.f;
    }

    // Draw the sword
    Rectangle source{0.f, 0.f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width * scale, weapon.height * scale};
    DrawTexturePro(weapon, source, dest, {origin}, rotation, WHITE);

    // DrawRectangleLines(  Draws a rectangle line on screen
    //     weaponCollisionRec.x,
    //     weaponCollisionRec.y,
    //     weaponCollisionRec.width,
    //     weaponCollisionRec.height,
    //     RED
    // );

     // // If direction is 0 we don't need to move.  Vector2Length takes a vector and returns a float representing how long the vector is.  We move if it isn't = to 0.0.
    // if (Vector2Length(direction) != 0.0) // lets us determine if vector has magnitude of 0 to decide whether to use idle or run animation.
    // {

    //     // set worldPos = worldPos + direction
    //     // Vector2Normalize(direction) is used to keep diagonal movement the same speed as cardinal direction speed.
    //     worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed)); // takes the quantity of 2nd element and subtracts from mapPos
    //     direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;                            // tunary operator can be used in place of single line if/else statments
    //     texture = run;
    // }
    // else
    // {
    //     texture = idle;
    // }
}

void Character::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0.f)
    {
        setAlive(false);
    }
}
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
//     Rectangle source{frame * width, 0.f, rightLeft * width, height}; // using first frame in animation(0.f, 0.f) then knight height and width
//     Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};  // where we wish to draw the knight in the window.  in width/height, this is where we scale
//     DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
// }

// void Character::undoMovement()
// {
//     worldPos = worldPosLastFrame;
// }

// Rectangle Character::getCollisionRec()
// {
//     return Rectangle{
//         screenPos.x,
//         screenPos.y,
//         width * scale,
//         height * scale
//     };
// }