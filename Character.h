#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "BaseCharacter.h"


class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);
    // Vector2 getWorldPos() { return worldPos; }      // Small functions can be condensed to 1 line ***Getters do not have a ; at the end of the functiton.
    // void setScreenPos(int winWidth, int winHeight); // To add a function outside of the class that would normally be in it, add a ; to the end of the function.  Cont on ln25.
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override; // This creates a public getter to access screenPos in enemy.cpp
    Rectangle getWeaponCollisionRec() {return weaponCollisionRec;}
    float getHealth() const {return health;}
    void takeDamage(float damage);
    // void undoMovement();
    // Rectangle getCollisionRec();

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
    float health{100.f};
    // Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    // Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    // Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
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

#endif