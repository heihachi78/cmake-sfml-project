#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

class SFMLWindow
{
    int m_window_width;
    int m_window_height;
    std::string m_window_name;
    int m_framerate_limit;
    sf::RenderWindow m_window;
    sf::VideoMode m_desktop;
    int m_screen_center_x;
    int m_screen_center_y;
    sf::VideoMode m_videoMode;
    sf::Vector2i m_screen_center;

public:
    SFMLWindow(
        const int           window_width, 
        const int           window_height,
        const std::string   window_name,
        const int           framerate_limit
    )
        : m_window_width    (window_width)
        , m_window_height   (window_height)
        , m_window_name     (window_name)
        , m_framerate_limit (framerate_limit)
    {
        m_desktop = sf::VideoMode::getDesktopMode();
        m_screen_center_x = (m_desktop.size.x - m_window_width) / 2;
        m_screen_center_y = (m_desktop.size.y - m_window_height) / 2;
        m_videoMode = sf::VideoMode(sf::Vector2u(m_window_width, m_window_height));
        m_window = sf::RenderWindow(m_videoMode, m_window_name);
        m_screen_center = sf::Vector2i(m_screen_center_x, m_screen_center_y);
        m_window.setFramerateLimit(m_framerate_limit);
        m_window.setPosition(m_screen_center);
    }

    void mainLoop()
    {
        while (m_window.isOpen())
        {
            while (const std::optional event = m_window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    m_window.close();
                }
            }

            m_window.clear();
            m_window.display();
        }
    }
};

int main()
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    const std::string WINDOW_NAME = "CMake SFML Project";
    const int FRAMERATE_LIMIT = 60;

    SFMLWindow gameWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, FRAMERATE_LIMIT);
    gameWindow.mainLoop();

    return 0;
}
