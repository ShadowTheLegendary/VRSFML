////////////////////////////////////////////////////////////
/// \mainpage SFML Documentation
///
/// \section welcome Welcome
/// Welcome to the official SFML documentation. Here you will find a detailed
/// view of all the SFML classes and functions. <br/>
/// If you are looking for tutorials, you can visit the official website
/// at <a href="https://www.sfml-dev.org/">www.sfml-dev.org</a>.
///
/// \section example Short example
/// Here is a short example, to show you how simple it is to use SFML:
///
/// \code
///
/// #include <SFML/Audio/Music.hpp>
///
/// #include <SFML/Graphics/RenderWindow.hpp>
/// #include <SFML/Graphics/Text.hpp>
/// #include <SFML/Graphics/Texture.hpp>
/// #include <SFML/Graphics/Sprite.hpp>
///
/// #include <SFML/Window/Event.hpp>
/// #include <SFML/Window/VideoMode.hpp>
///
/// #include <SFML/Base/Optional.hpp>
///
/// int main()
/// {
///     // Create the main window
///     sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");
///
///     // Load a sprite to display
///     const auto texture = sf::Texture::loadFromFile("cute_image.jpg").value();
///     sf::Sprite sprite(texture.getRect());
///
///     // Create a graphical text to display
///     const auto font = sf::Font::openFromFile("arial.ttf").value();
///     sf::Text text(font, "Hello SFML", 50);
///
///     // Load a music to play
///     auto music = sf::Music::openFromFile("nice_music.ogg").value();
///
///     // Play the music
///     music.play();
///
///     // Start the game loop
///     while (true)
///     {
///         // Process events
///         while (const sf::base::Optional event = window.pollEvent())
///         {
///             // Close window: exit
///             if (event->is<sf::Event::Closed>())
///                 return 0;
///         }
///
///         // Clear screen
///         window.clear();
///
///         // Draw the sprite
///         window.draw(sprite, texture);
///
///         // Draw the string
///         window.draw(text);
///
///         // Update the window
///         window.display();
///     }
/// }
/// \endcode
////////////////////////////////////////////////////////////
