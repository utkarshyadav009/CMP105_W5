#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombie.setTexture(&zombTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::D))
	{
		zombie.walk.setFlipped(false);
		zombie.move(speedx * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{   
		//Animation::setFlipped (true) ;
		zombie.walk.setFlipped(true);
		zombie.move(-speedx * dt, 0);
	}
}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie); 
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}