/*

	Copyright[2021] Justin Cheok

*/


#include "Triangle.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

Triangle *fTree(double length, int depth,
	float centerX, float centerY, int level);

int level = 0;
int t = 0;

Triangle* triangle;

int main(int argc, char** argv) {
double length;  // Change to L
int depth;  // change to N
float centerX = windowX / 2;
float centerY = windowY / 2;

if (argc == 3) {
if (sscanf(argv[1], "%lf", &length) != 1) {
std::cout << "Invalid Argument" << std::endl;
return -1;
}
if (sscanf(argv[2], "%d", &depth) != 1) {
std::cout << "Invalid Argument" << std::endl;
return -1;
}
} else {
length = 100;  // length of each side
depth = 5;  // how many recursions
}
triangle = (Triangle*)malloc((pow(3, 10) + 1) * sizeof(Triangle));
//int test = (pow(3, depth) + 1);
for (int i = 0; i < argc; ++i) {
std::cout << "argc[" << i << "] : " << argv[i] << "\n";
}
//float windowX = 800.f;
//float windowY = 800.f;
int n = depth;

Triangle* root = fTree(length, depth, centerX, centerY, level);
Triangle triangle = *root;
for (int i = 0; i <= pow(3, n); ++i) {
//std::cout << "i " << i << std::endl;
//root[i].printCenter();
}
// std::cout << "Level " << level << std::endl;
// std::cout << "CenterX " << centerX << std::endl;
// std::cout << "CenterY " << centerY << std::endl;
// std::cout << "N " << n << std::endl << "Length " << length << std::endl;
sf::ContextSettings settings;
settings.antialiasingLevel = 1;
//sf::RenderWindow window(sf::VideoMode(windowX, windowY), "SFML Window", sf::Style::Default, settings);
sf::RenderWindow window(sf::VideoMode(4 * length, 3 * length), "SFML Window", sf::Style::Default, settings);
while (window.isOpen()) {
sf::Event event;
while (window.pollEvent(event)) {
switch (event.type) {
case sf::Event::Closed:
window.close();
break;
case sf::Event::Resized:
printf("New window width: %i New window height: % i \n", event.size.width, event.size.height);
break;
case sf::Event::TextEntered:
//if (event.text.unicode < 128) {
//printf("%c", event.text.unicode);
//}
break;
default:
break;
}
}
window.clear(sf::Color::White);

for(int i = 0; i < t; ++i) {
Triangle triangle = *(root + i);
window.draw(triangle);
}
window.display();
}
return 0;
}

Triangle *fTree(double length, int depth, float centerX, float centerY, int level) {
// std::cout << "FTREE LEVEL: " << level << std::endl;
// std::cout << "FTREE length: " << length << std::endl;
// std::cout << "FTREE depth: " << depth << std::endl;
int curr = t;
int levelI = level;
triangle[curr].TriangleX(length, centerX, centerY);
t++;
levelI++;
if (levelI <= depth) {
float height = length * (sqrt(3) / 2);
// std::cout << "HEIGHTT " << height << std::endl;
float leftX = (centerX - (length / 2));
// std::cout << "=========CENTERX= " << centerX << std::endl;
float leftY = (centerY - (height / 3));
float rightX = (centerX + (length / 2));
float rightY = (centerY - (height / 3));
float bottomX = (centerX);
float bottomY = (centerY + length / 2);
int lengthI = length / 2;
height = lengthI * (sqrt(3) / 2);
float leftCenterX = leftX;
float leftCenterY = leftY - (height / 2);
triangle[curr].left = fTree(lengthI, depth, leftCenterX, leftCenterY, levelI);
// std::cout << "LENGTHI " << lengthI << std::endl;
float rightCenterX = rightX + (lengthI/2);
float rightCenterY = rightY + (height / 3);
triangle[curr].right = fTree(lengthI, depth, rightCenterX, rightCenterY, levelI);
float bottomCenterX = bottomX - (lengthI / 2);
float bottomCenterY = bottomY + (height / 3);
triangle[curr].bottom = fTree(lengthI, depth, bottomCenterX, bottomCenterY, levelI);
}
return &triangle[curr];
}
