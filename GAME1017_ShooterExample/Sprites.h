#pragma once
#include <vector>
#include "SDL.h"
#include "SDL_mixer.h"
using namespace std;

class Sprite
{
protected:
	SDL_Rect m_rSrc; // Rectangle for source pixels.
	SDL_Rect m_rDst; // Rectangle for destination window.
	int m_x,			// X coordinate. 
		m_y,			// Y coordinate.
		m_angle;		// Angle of sprite.
public:
	Sprite();
	Sprite(SDL_Rect s, SDL_Rect d);
	SDL_Rect* GetSrcP(); 
	SDL_Rect* GetDstP();
	double GetAngle();
};

class AnimatedSprite : public Sprite
{
protected:
	int m_iSprite,	// Which sprite to display for animation.
		m_iSpriteMax,	// How many sprites total.
		m_iFrame,	// Frame counter.
		m_iFrameMax;	// Number of frames per sprite.

public:
	AnimatedSprite(int a, int fm, int sm, SDL_Rect s, SDL_Rect d);
	void Animate();
};

class Player : public AnimatedSprite
{
public:
	Player(SDL_Rect s, SDL_Rect d);
	// Add more members later.
};

class Bullet : public Sprite
{
private:
	int m_speed;
	bool m_active;
public:
	Bullet(SDL_Rect s, SDL_Rect d, int spd);
	void Update();
};

class Enemy : public AnimatedSprite
{
private:
	int m_bulletTimer,
		m_timerMax; // Basically fire rate of bullets.
	vector<Bullet*>* m_pBulletVec; // Pointer to the enemy bullet vector from Engine.
	Mix_Chunk* m_pPew;
public:
	Enemy(SDL_Rect s, SDL_Rect d, vector<Bullet*>* bVec, Mix_Chunk* c, int fr = 120); // Default function params go in prototypes.
	void Update();
	// Add more members later.
};

