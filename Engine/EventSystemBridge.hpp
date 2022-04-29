#ifndef __EVENT_SYSTEM_BRIDGE_HPP__
#define __EVENT_SYSTEM_BRIDGE_HPP__

//==============================================================================

#include "../Events/Event.hpp"

class EventSystemBridge {
private:
    EventSystemBridge() = default;

public:
    virtual void start();
    virtual void stop();
    virtual const Event* parseEvent();
    virtual const Event* pollEvent();
    virtual void appendEvent(const Event& event);
    virtual Event popEvent();

};
//==============================================================================

#endif //__EVENT_SYSTEM_BRIDGE_HPP__