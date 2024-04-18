// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include "button.h"
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

    Color mainColor(rand() % 230 + 26, rand() % 230 + 26, rand() % 230 + 26);

    int btnClick = 0;
    int btn2Click = 0;

    int colorWheel = 0;
    int shapeWheel = 0;

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

    Button btn("Theme Rainbow", { 350, 50 }, 20, sf::Color::Red, sf::Color::Black);
    btn.setPosition({ 100, 100 });
    btn.setFont(instructionsFont);


    Button btn2("Shape Circle", { 350, 50 }, 20, sf::Color::Red, sf::Color::Black);
    btn2.setPosition({ 500, 100 });
    btn2.setFont(instructionsFont);

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
                if (event.mouseButton.button == sf::Mouse::Left && !btn.isMouseOver(window) && !btn2.isMouseOver(window))
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if (vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if (points.size() == 0)
                    {
                        Color c(rand() % 230 + 26, rand() % 230 + 26, rand() % 230 + 26);

                        Color r(rand() % 230 + 26, 0, 0);

                        Color g(0, rand() % 230 + 26, 0);

                        Color b(0, 0, rand() % 230 + 26);



                        if (colorWheel == 0)
                        {
                            points.push_back({ Vector2f(event.mouseButton.x, event.mouseButton.y), c });
                        }
                        else if (colorWheel == 1)
                        {
                            points.push_back({ Vector2f(event.mouseButton.x, event.mouseButton.y), r });
                        }
                        else if (colorWheel == 2)
                        {
                            points.push_back({ Vector2f(event.mouseButton.x, event.mouseButton.y), g });
                        }
                        else if (colorWheel == 3)
                        {
                            points.push_back({ Vector2f(event.mouseButton.x, event.mouseButton.y), b });
                        }
                    }
                }

                if (event.mouseButton.button == sf::Mouse::Left && btn.isMouseOver(window))
                {
                    btnClick++;
                    colorWheel++;

                    cout << "Color Theme Clicked" << endl;

                    if (btnClick == 1) {
                        btn.settxt("Theme Red");
                        mainColor = Color::Red;
                    }
                    if (btnClick == 2) {
                        btn.settxt("Theme Green");
                        mainColor = Color::Green;
                    }
                    if (btnClick == 3) {
                        btn.settxt("Theme Blue");
                        mainColor = Color::Blue;
                    }
                    if (btnClick == 4)
                    {
                        btn.settxt("Theme Rainbow");
                        btnClick = 0;
                        colorWheel = 0;
                    }
                }

                if (event.mouseButton.button == sf::Mouse::Left && btn2.isMouseOver(window))
                {
                    btn2Click++;
                    shapeWheel++;


                    cout << "Shape Picker Clicked" << endl;

                    if (btn2Click == 1) { btn2.settxt("Shape Triagnle"); }
                    if (btn2Click == 2) { btn2.settxt("Shape Square"); }
                    if (btn2Click == 3) { btn2.settxt("Shape Pentagon"); }
                    if (btn2Click == 4)
                    {
                        btn2.settxt("Shape Circle");
                        btn2Click = 0;
                        shapeWheel = 0;
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
                Color c(rand() % 230 + 26, rand() % 230 + 26, rand() % 230 + 26);


                Color r(rand() % 230 + 26, 0, 255 % (i + 1) / 10);

                Color g(255 % (i + 1) / 10, rand() % 230 + 26, 0);

                Color b(255 % (i + 1) / 10, 0, rand() % 230 + 26);

                Color mainColor(rand() % 230 + 26, rand() % 230 + 26, rand() % 230 + 26);

                if (colorWheel == 0)
                {
                    points.push_back({ Vector2f((points.back().location.x + vertices.at(randomNumber).x) / 2, (points.back().location.y + vertices.at(randomNumber).y) / 2),c });

                }
                else if (colorWheel == 1)
                {
                    points.push_back({ Vector2f((points.back().location.x + vertices.at(randomNumber).x) / 2, (points.back().location.y + vertices.at(randomNumber).y) / 2),r });

                }
                else if (colorWheel == 2)
                {
                    points.push_back({ Vector2f((points.back().location.x + vertices.at(randomNumber).x) / 2, (points.back().location.y + vertices.at(randomNumber).y) / 2),g });

                }
                else if (colorWheel == 3)
                {
                    points.push_back({ Vector2f((points.back().location.x + vertices.at(randomNumber).x) / 2, (points.back().location.y + vertices.at(randomNumber).y) / 2),b });

                }




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
            btn.drawTo(window);
            btn2.drawTo(window);

            instructions.setPosition(10.f, 10.f);
            if (vertices.size() < 3)
            {
                instructions.setString("Please click to place Vertex #" + to_string(vertices.size() + 1));
            }
            else
            {
                instructions.setString("Please click to place the starting point");
            }
            window.draw(instructions);
        }
        for (int i = 0; i < vertices.size(); i++)
        {


            CircleShape circ(4);


            if (shapeWheel == 0)
            {

                circ.setPosition(Vector2f(vertices[i].x, vertices[i].y));
                circ.setFillColor(mainColor);
                window.draw(circ);
            }
            else if (shapeWheel == 2)
            {
                CircleShape sqr(4, 4);
                sqr.setPosition(Vector2f(vertices[i].x, vertices[i].y));
                sqr.setFillColor(mainColor);
                window.draw(sqr);
            }
            else if (shapeWheel == 1)
            {
                CircleShape tri(4, 3);
                tri.setPosition(Vector2f(vertices[i].x, vertices[i].y));
                tri.setFillColor(mainColor);
                window.draw(tri);
            }
            else if (shapeWheel == 3)
            {
                CircleShape pent(4, 5);
                pent.setPosition(Vector2f(vertices[i].x, vertices[i].y));
                pent.setFillColor(mainColor);
                window.draw(pent);
            }

        }
        for (int i = 0; i < points.size(); i++)
        {
            CircleShape circle(4);


            if (shapeWheel == 0)
            {
                circle.setPosition(Vector2f(points[i].location.x, points[i].location.y));
                circle.setFillColor(points[i].color);
                window.draw(circle);
            }
            else if (shapeWheel == 1)
            {
                CircleShape triangle(4, 3);
                triangle.setPosition(Vector2f(points[i].location.x, points[i].location.y));
                triangle.setFillColor(points[i].color);
                window.draw(triangle);
            }
            else if (shapeWheel == 2)
            {
                CircleShape square(4, 4);
                square.setPosition(Vector2f(points[i].location.x, points[i].location.y));
                square.setFillColor(points[i].color);
                window.draw(square);
            }
            else if (shapeWheel == 3)
            {
                CircleShape pentagon(4, 5);
                pentagon.setPosition(Vector2f(points[i].location.x, points[i].location.y));
                pentagon.setFillColor(points[i].color);
                window.draw(pentagon);
            }


        }
        window.display();
    }
}
