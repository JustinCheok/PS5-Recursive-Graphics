/*

	Copyright[2021] Justin Cheok

*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <cstdio>
#include <cmath>

typedef void *TREE;

const float windowX = 800.f;
const float windowY = 800.f;

class Triangle : public sf::Drawable, public sf::Transformable {
public:
void TriangleX(double length, float centerX, float centerY);
Triangle() {
left = NULL, right = NULL, bottom = NULL;
};
//void printCenter();
Triangle* left, * right, * bottom;
	
private:
virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
float length;
float centerX;
float centerY;
};
#endif
