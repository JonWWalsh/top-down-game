#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture) //:
    // worldPos(pos),
    // texture(idle_texture),
    // idle(idle_texture),
    // run(run_texture)
    {
        worldPos = pos;
        texture = idle_texture;
        idle = idle_texture;
        run = run_texture;
        width = texture.width / maxFrames;
        height = texture.height;
        speed = 3.5f;
    }


    void Enemy::tick(float deltaTime)
    {
        if (!getAlive()) return;
        //Before
        // Enemy chase steps:
        // 1. Get vector from goblin to knight (toTarget)
        // Vector2 toTarget = Vector2Subtract(target->getScreenPos(), screenPos); // This function returns the result of the character's screenPos - enemey screenPos.  (needs public getter in character.h)
        // 2. Normalize acquired vector (toTarget)        
        // toTarget = Vector2Normalize(toTarget); 
        // 3. Multiply toTarget by speed
        // toTarget = Vector2Scale(toTarget, speed);
        // 4. Move enemy to knight (set worldPos)
        // worldPos = Vector2Add(worldPos, toTarget);
        // screenPos = Vector2Subtract(worldPos, target->getWorldPos()); 
        // BaseCharacter::tick(deltaTime);

        // After
        velocity = Vector2Subtract(target->getScreenPos(), getScreenPos()); 
        if (Vector2Length(velocity) < radius) velocity = {};
        //screenPos = Vector2Subtract(worldPos, target->getWorldPos()); //updates enemy screenPos so it isn't in a static position.
        BaseCharacter::tick(deltaTime); //BaseCharacter now handles steps 2-4.

        if (CheckCollisionRecs(target->getCollisionRec(), getCollisionRec()))
        {
            target->takeDamage(damagePerSec * deltaTime);
        }
    }
        Vector2 Enemy::getScreenPos()
        {
            return Vector2Subtract(worldPos, target->getWorldPos());
        }



        // worldPosLastFrame = worldPos;

        // // update animation frame
        // runningTime += deltaTime; // since dT is already being called into the function GetFrameTime() can be replaced with deltaTime.
        // if (runningTime >= updateTime)
        // {
        // frame++;
        // runningTime = 0.f;
        // if (frame > maxFrames)
        //     frame = 0;
        // }
        // // draw the character
        // Rectangle source{frame * width, 0.f, rightLeft * width, height}; // using first frame in animation(0.f, 0.f) then knight height and width
        // Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};  // where we wish to draw the knight in the window.  in width/height, this is where we scale
        // DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
    
    
    // void Enemy::undoMovement()
    // {
    //     worldPos = worldPosLastFrame;
    // }

    // Rectangle Enemy::getCollisionRec()
    // {
    //     return Rectangle{
    //     screenPos.x,
    //     screenPos.y,
    //     width * scale,
    //     height * scale
    //     };
    // }