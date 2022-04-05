#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    //Vector2 getWorldPos() { return worldPos; } // Small functions can be condensed to 1 line ***Getters do not have a ; at the end of the functiton.
    // void setScreenPos(int winWidth, int winHeight); // To add a function outside of the class that would normally be in it, add a ; to the end of the function.  Cont on ln25.
    virtual void tick(float deltaTime) override;
    // void undoMovement();
    // Rectangle getCollisionRec();
    void setTarget(Character* character) {target = character;}
    virtual Vector2 getScreenPos() override;
private:
    Character* target; // creates a pointer to character called target * = dereference operator.
    float damagePerSec{10.f};
    float radius{25.f};
    // Texture2D texture{LoadTexture("characters/goblin_idle_spritesheet.png")};
    // Texture2D idle{LoadTexture("characters/goblin_idle_spritesheet.png")};
    // Texture2D run{LoadTexture("characters/goblin_run_spritesheet.png")};
    // Vector2 screenPos{};
    // Vector2 worldPos{};
    // Vector2 worldPosLastFrame{};
    // // 1 : facing right, -1 : facing left
    // float rightLeft{1.0f};
    // // animation variables
    // float runningTime{};
    // int frame{};
    // int maxFrames{6};
    // float updateTime{1.0f / 12.0f};
    // float speed{4.0f};
    // float width{};
    // float height{};
    // float scale{4.0f};
};