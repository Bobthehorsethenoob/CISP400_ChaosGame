// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
//comment3
// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
    // Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);
    struct ColoredPoint
    {
        Vector2f location;
        Color color;
    };



    vector<Vector2f> vertices;
    vector<ColoredPoint> points;
    srand(0);
    Font instructionsFont;
    if (!instructionsFont.loadFromFile("Starcruiser.ttf"))
    {
        window.close();
        // error...
        //¯\_(-_-)_/¯
    }
    Text instructions;
    instructions.setFont(instructionsFont);
    instructions.setCharacterSize(64);
    instructions.setFillColor(Color::Red);
    
    
        
	while (window.isOpen())
	{
        /*
		****************************************
		Handle the players input
		****************************************
		*/
        Event event;
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed)
            {
				// Quit the game when the window is closed
				window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if(vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if(points.size() == 0)
                    {
                        Color c(rand() % 230+26, rand() % 230+26, rand() % 230+26);
                        points.push_back({ Vector2f(event.mouseButton.x, event.mouseButton.y), c});
                        ///fourth click
                        ///push back to points vector
                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
        /*
		****************************************
		Update
		****************************************
		*/

        if (points.size() > 0)
        {
            int randomNumber;
     //       randomNumber = rand() % 3;
            for (int i = 0; i < max(int(log2(points.size())), 1); i++)
            {
                randomNumber = rand() % 3;
                Color c(rand() % 230+26, rand() % 230+26, rand() % 230+26);
                points.push_back({ Vector2f((points.back().location.x + vertices.at(randomNumber).x) / 2, (points.back().location.y + vertices.at(randomNumber).y) / 2),c });
            }
            cout << points.size() << endl;
            ///generate more point(s)
            ///select random vertex
            ///calculate midpoint between random vertex and the last point in the vector
            ///push back the newly generated coord.
        }

        /*
		****************************************
		Draw
		****************************************
		*/
        window.clear();
        
        if (points.size() == 0)
        {
            
            instructions.setPosition(10.f, 10.f);
            if (vertices.size() < 3)
                {
                    instructions.setString("Please click to place Vertex #" + to_string(vertices.size()+1));
                }
                else
                {
                    instructions.setString("Please click to place the starting point");
                }
                window.draw(instructions);
            }
        for(int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rect(Vector2f(10,10));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }
        for (int i = 0; i < points.size(); i++)
        {
            CircleShape circ(4);
            circ.setPosition(Vector2f(points[i].location.x, points[i].location.y));
            circ.setFillColor(points[i].color);
            window.draw(circ);
        }
        window.display();
    }
}
