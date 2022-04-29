#include "Event.hpp"

Event::Event(EventType type)
    :type(type) {}

EventType Event::getEventType() const
{
    return type;
}
    
MouseEvent::MouseEvent(const Vector2d& pos, EventType type)
    :Event(type), pos(pos) {}

Vector2d MouseEvent::getPos() const 
{
    return pos;
}

KeyEvent::KeyEvent(int key, EventType type)
    :Event(type), key(key) {}


RedrawEvent::RedrawEvent()
    :Event(EventType::Redraw) {}