/*

	Copyright[2021] Justin Cheok

*/

#include "Triangle.h"

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
//int n = 1;
float height = length * (sqrt(3) / 2);
sf::VertexArray triangle(sf::Triangles, 3);
triangle[0].position = sf::Vector2f(centerX - (length / 2), centerY - (height / 3));
triangle[0].color = sf::Color::Red;
triangle[1].position = sf::Vector2f(centerX + (length / 2), centerY - (height / 3));
triangle[1].color = sf::Color::Blue;
triangle[2].position = sf::Vector2f(centerX, centerY + length/2);
triangle[2].color = sf::Color::Green;
target.draw(triangle);
}

void Triangle::TriangleX(double L, float centerX, float centerY) {
this->length = (float)L;
this->centerX = (float)centerX;
this->centerY = (float)centerY;
}

/*
void Triangle::printCenter() {
std::cout << "centerX " << centerX << std::endl;
std::cout << "centerY " << centerY << std::endl;
std::cout << "length " << length << std::endl;
}
*/
