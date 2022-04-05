// #ifndef states that if BaseCharacter.h is already included in the main.cpp file it will not be recopied which would lead to an error.  You must define BASE_CHARACTER_H using #define
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{
    public:
        BaseCharacter();
        Vector2 getWorldPos() { return worldPos; }
        virtual void tick(float deltaTime);
        void undoMovement();
        Rectangle getCollisionRec();
        virtual Vector2 getScreenPos() = 0; // function is declared here but will be defined in character and enemy files.  Thus, we will make this a Pure Virtual Function and are marked with = 0.  One a PVF is used on a class, that class is said to be an Abstract Class.  This means we cannot create instances of it, only derive child classes from it.
        bool getAlive() {return alive;}
        void setAlive(bool isAlive) {alive = isAlive;}
    protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    // Vector2 screenPos{}; // Deleted as screenPos is an unnecessary variable and can be stored/accessed within BaseCharacter.
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // 1 : facing right, -1 : facing left
    float rightLeft{1.0f};
    // animation variables
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.0f / 12.0f};
    float speed{4.0f};
    float width{};
    float height{};
    float scale{4.0f};
    Vector2 velocity{};
    private:
        bool alive{true};
};

#endif // used to end the #ifndef inclusion