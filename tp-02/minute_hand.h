#include "Event.h"

#include <iostream>
#include <vector>

class MinuteHand {

public:
    unsigned int getMinutes() const { return _minutes; }
    void         advance() { _minutes++; }

private:
    unsigned int _minutes = 0u;
};

class SecondHand {

public:
    SecondHand(MinuteHand& minute)
        : _min_hand { minute } {}

    unsigned int getSeconds() const { return _secondes; }
    void         advance() {
        if (_secondes == 60) {
            _secondes = 0;
            _min_hand.advance();
        } else {
            _secondes++;
        }
    }

private:
    unsigned int _secondes = 0u;
    MinuteHand&  _min_hand;
};

class Clock {

public:
    Clock()
        : _events() {};
    void         tick() { _second_hand.advance(); }
    unsigned int getMinutes() const { return _minute_hand.getMinutes(); }
    unsigned int getSeconds() const { return _second_hand.getSeconds(); }
    void         add();

    void add_event(const Event& event) { _events.emplace_back(event); }

private:
    MinuteHand         _minute_hand;
    SecondHand         _second_hand { _minute_hand };
    std::vector<Event> _events;
};

std::ostream& operator<<(std::ostream& stream, const Clock& clock) {
    return stream << clock.getMinutes() << " min " << clock.getSeconds() << " sec " << std::endl;
}