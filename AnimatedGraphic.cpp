#include "AnimatedGraphic.h"


AnimatedGraphic::AnimatedGraphic(float x, float y, int width, int height, std::string textureID,int animationSpeed) 
	:GameObject(x, y, width, height, textureID) ,m_AnimationSpeed(animationSpeed)
{

}

void AnimatedGraphic::Draw(SDL_Renderer* pRenderer)
{
	GameObject::Draw(pRenderer);
}
void AnimatedGraphic::Update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_AnimationSpeed)) % 2));
}
void AnimatedGraphic::Clean()
{

}