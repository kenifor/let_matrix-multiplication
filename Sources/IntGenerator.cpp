#include "IntGenerator.h"

#include <random>
#include <time.h>

#include <iostream>

IntGenerator::IntGenerator()
{
    left_border_ = static_cast<int>(DEFAULT::LEFT_BORDER);
    right_border_ = static_cast<int>(DEFAULT::RIGHT_BORDER);
}

IntGenerator::IntGenerator(const IntGenerator& generator)
{
    *this = generator;
}

IntGenerator::IntGenerator(int left_border, int right_border):
    IntGenerator()
{
    if (left_border <= right_border)
    {
        left_border_ = left_border;
        right_border_ = right_border;
    }
}

IntGenerator IntGenerator::operator=(const IntGenerator& rhs)
{
    IntGenerator generator;

    generator.left_border_ = rhs.left_border_;
    generator.right_border_ = rhs.right_border_;
    generator.randomizer_ = rhs.randomizer_;

    return generator;
}

int IntGenerator::getNumber()
{
    return getNumber(left_border_, right_border_);
}

int IntGenerator::getNumber(int left_border, int right_border)
{
    srand(randomizer_++ * time(NULL));

    int random = left_border + rand() % (right_border - left_border + 1);

    return random;
}

int IntGenerator::randomizer_ = 0;
