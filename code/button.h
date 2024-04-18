#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class Button {

public:
	
	Button() {}

	Button(std::string txt, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color txtColor)
	{
		text.setString(txt);
		text.setColor(txtColor);
		text.setCharacterSize(charSize);

		button.setSize(size);
		button.setFillColor(bgColor);

	}

	void settxt(std::string sentence)
	{
		text.setString(sentence);
	}


	void setFont(sf::Font& font)
	{
		text.setFont(font);
	}

	void setBackColor(sf::Color color)
	{
		button.setFillColor(color);
	}

	void setTextColor(sf::Color color)
	{
		text.setColor(color);
	}

	void setPosition(sf::Vector2f pos)
	{
		button.setPosition(pos);

		float xpos = (pos.x + button.getLocalBounds().width / 4 - (text.getLocalBounds().width / 4));
		float ypos = (pos.y + button.getLocalBounds().height / 4 - (text.getLocalBounds().height / 4));
		text.setPosition({ xpos, ypos });



	}

	void drawTo(sf::RenderWindow& window)
	{
		window.draw(button);
		window.draw(text);

	}

	bool isMouseOver(sf::RenderWindow& window)
	{
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnPosX = button.getPosition().x;
		float btnPosY = button.getPosition().y;

		float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
		float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;


		if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
		{
			return true;
		}
		return false;
	}

private:
	sf::RectangleShape button;
	sf::Text text;
};