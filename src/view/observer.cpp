//
// Created by ali-masa on 3/17/20.
//

#include "observer.h"

using namespace std;

Observer::Observer(ostream &streamer):m_streamer(&streamer){}

void Observer::update(Subject *subject) const
{
    *(m_streamer) << (subject->notifyMessage()) << endl;
}

void Observer::setStreamer(ostream &streamer)
{
    m_streamer = &streamer;
}
