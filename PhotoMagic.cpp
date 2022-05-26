/*Copyright 2022  Mandar Kapadia */
/**
 * photoMagci.cpp - in this file we are able to take a file and a seed and encypt and decypt the image
 * 
 * 2/7/22
 * 
 * mandar Kapadia
 * */


#include<iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"

void transform(sf::Image& image, FibLFSR* seed);
int main(int argc, char* argv[]) {
  sf::Image input;
  sf::Image output;
  std::string temp = argv[3];
  std::string seedValue =  "";
  for (unsigned int i = 0; i < temp.size(); i++) {
    temp = std::to_string(static_cast<int>(temp[i]) % 2);
  }
  for (unsigned int i = seedValue.size(); i < 16; i++) {
    seedValue.push_back(0);
  }
  FibLFSR seed(seedValue);

  if (!input.loadFromFile(argv[1]))
    return -1;
  if (!output.loadFromFile(argv[1]))
    return -1;

  transform(output, &seed);
  if (!output.saveToFile(argv[2]))
    return -1;
  sf::RenderWindow window1(sf::VideoMode(input.getSize().x, input.getSize().y), "orginal");//NOLINT
  sf::RenderWindow window2(sf::VideoMode(output.getSize().x, output.getSize().y), "encrypted");//NOLINT
  // put texture on input and output
  sf::Texture textureInput;
  textureInput.loadFromImage(input);
  sf::Texture textureOutput;
  textureOutput.loadFromImage(output);
  sf::Sprite spriteInput;
  spriteInput.setTexture(textureInput);
  sf::Sprite spriteOutput;
  spriteOutput.setTexture(textureOutput);

  while (window1.isOpen() && window2.isOpen()) {
    sf::Event event;
    while (window1.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window1.close();
    }
    while (window2.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window2.close();
    }
    window1.clear();
    window1.draw(spriteInput);
    window1.display();
    window2.clear();
    window2.draw(spriteOutput);
    window2.display();
  }
}
void transform(sf::Image& image, FibLFSR* seed) {
    sf::Color p;
    for (int x = 0; x < image.getSize().x; x++) {
        for (int y = 0; y < image.getSize().y; y++) {
            p = image.getPixel(x, y);
            p.r = (p.r ^ seed->generate(8));
            p.g = (p.g ^ seed->generate(8));
            p.b = (p.b ^ seed->generate(8));
            image.setPixel(x, y, p);
        }
    }
}
