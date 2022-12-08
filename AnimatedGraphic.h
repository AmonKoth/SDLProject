#ifndef ANIMATED_GRAPHIC_H
#define ANIMATED_GRAPHIC_H

#include "GameObject.h"

class AnimatedGraphic : public GameObject
{
public:
	AnimatedGraphic(float x, float y, int width, int height, std::string textureID, int animationSpeed);
	~AnimatedGraphic() {};

	void Draw(SDL_Renderer* pRenderer);
	void Update();
	void Clean();

private:
	int m_AnimationSpeed;

};


#endif // !ANIMATED_GRAPHIC_H
