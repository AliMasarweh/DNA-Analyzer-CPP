//
// Created by ali-masa on 3/17/20.
//

#ifndef DNANALYZER_OBSERVER_H
#define DNANALYZER_OBSERVER_H


#include <ostream>

class Subject
{
public:
    virtual ~Subject() {};
    virtual std::string notifyMessage() = 0;
};

class Observer
{
public:
    Observer(std::ostream& streamer);
    void update(Subject* m_subject) const;
    void setStreamer(std::ostream& streamer);

private:
    std::ostream* m_streamer;
};


#endif //DNANALYZER_OBSERVER_H
