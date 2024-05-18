// Renderable.h
#ifndef RENDERABLE_H
#define RENDERABLE_H

class Renderable {
public:
    virtual void render() const = 0;
    virtual ~Renderable() = default;
};

#endif // RENDERABLE_H
