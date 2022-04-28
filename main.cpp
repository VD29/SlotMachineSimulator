#include "SlotMachine.h"

#include <windows.h>

int main()
{
    HWND hWnd = GetConsoleWindow();

    unique_ptr<ResourceManager> rManager = make_unique<ResourceManager>();
    
    rManager->loadFont("Cowboys", "resources/Cowboys.ttf");
    rManager->loadFont("arial", "resources/arial.ttf");
    rManager->loadTexture("chassis", "resources/chassis.png");
    rManager->loadTexture("lemon", "resources/lemon.png");
    rManager->loadTexture("heart", "resources/heart.png");
    rManager->loadTexture("diamonds", "resources/diamonds.png");
    rManager->loadTexture("spades", "resources/spades.png");
    rManager->loadTexture("trefoil", "resources/trefoil.png");
    rManager->loadTexture("bell", "resources/bell.png");
    rManager->loadTexture("bag", "resources/bag.png");
    rManager->loadTexture("clubs", "resources/clubs.png");
    
    unique_ptr<SlotMachine> machine = make_unique<SlotMachine>(*rManager);
    
    ShowWindow(hWnd, SW_HIDE);
    RenderWindow window(VideoMode(650, 800), "BIG WIN");
    window.setKeyRepeatEnabled(false);



    while (window.isOpen())
    {
        window.setFramerateLimit(300);

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::Resized)
            {
                FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(View(visibleArea));
            }
            Vector2i mouse = Mouse::getPosition(window);
            machine->eventsHandler(&event, mouse);
        }

        window.clear(Color::Black);
        machine->drawer(&window);
        window.display();

    }

    return 0;
}