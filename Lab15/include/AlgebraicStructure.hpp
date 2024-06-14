#pragma once

template <typename T>
class AlgebraicStructure {
public:
    virtual ~AlgebraicStructure() = default;
    virtual T add() = 0;
    virtual T multiply() = 0;
};