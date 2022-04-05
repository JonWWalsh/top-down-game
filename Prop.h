#include "raylib.h"
// Variables get initialized in the order that they are declared in the header file, regardless of how they appear in the .cpp file.
class Prop
{
    public:
        Prop(Vector2 pos, Texture2D tex);
        void Render(Vector2 knightPos);
        Rectangle getCollisionRec(Vector2 kightPos);
    private:
        Texture2D texture{};
        Vector2 worldPos{};
        float scale{4.0f};
};