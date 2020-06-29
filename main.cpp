#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

sf::Sprite * CreateBackground(sf::Texture & texture, sf::RenderWindow & window)
{
	sf::Sprite * background = new sf::Sprite;

	sf::Vector2u texture_size = texture.getSize(); //Get size of texture.
    sf::Vector2u window_size  = window.getSize();  //Get size of window.

    float scale_x = (float)window_size.x / texture_size.x;	  //Calculate scale.
    float scale_y = (float)window_size.y / texture_size.y;    //Calculate scale.

    background->setTexture(texture);
    background->setScale(scale_x, scale_y);

    return background;
}

int main()
{
	sf::Event 	 main_event;
	sf::Texture  background_texture;

	background_texture.loadFromFile("Pictures/background.png");

	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	sf::RenderWindow window(sf::VideoMode(modes[0].width, modes[0].height), "", sf::Style::Fullscreen);
	auto background = CreateBackground(background_texture, window);

	while (window.isOpen())
    {
    	while(window.pollEvent(main_event))
		{
			switch(main_event.type)
			{
				case sf::Event::KeyPressed:
				{	
					if(main_event.key.code == sf::Keyboard::Escape)
						window.close();

					break;
				}
			}
		}

		window.clear(sf::Color::White);
		window.draw(*background);
		window.display();
    }

    return 0;
}