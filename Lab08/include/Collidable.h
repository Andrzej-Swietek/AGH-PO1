// Collidable.h
#ifndef COLLIDABLE_H
#define COLLIDABLE_H

class Collidable {
public:

    /**Virtual Method Allowing object to colide
     * @return no return
    */
    virtual void collide() const = 0;


    /**
     * Virtual Destructor for Colidable class
    */
    virtual ~Collidable() = default;
};

#endif // COLLIDABLE_H
