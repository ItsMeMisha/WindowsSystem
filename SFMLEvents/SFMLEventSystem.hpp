#ifndef __SFML_EVENT_SYSTEM_HPP__
#define __SFML_EVENT_SYSTEM_HPP__

//==============================================================================

#include "../Engine/EventSystemBridge.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class SFMLEventSystem : public EventSystemBridge {
private:
    SFMLEventSystem() = default;
    sf::RenderWindow* rootWin;

public:
    void start() override;
    void stop() override;
    const Event* parse_event() override;
    const Event* poll_event() override;
    void append_event(const Event& event) override;
    Event pop_event() override;
    static SFMLEventSystem* init(sf::RenderWindow* rootWindow);
};

//==============================================================================

#endif //__SFML_EVENT_SYSTEM_HPP__