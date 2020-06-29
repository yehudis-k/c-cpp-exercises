//
// Created by student on 31/05/2020.
//

#ifndef ZOO_IBIRD_H
#define ZOO_IBIRD_H

class Ibird
{
public:
    virtual const unsigned int get_height()const = 0;
    virtual const unsigned int get_wing_span()const = 0;
};

#endif //ZOO_IBIRD_H
