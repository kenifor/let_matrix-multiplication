#ifndef INTGENERATOR_H
#define INTGENERATOR_H

class IntGenerator
{
public:
    IntGenerator();
    IntGenerator(const IntGenerator& generator);
    IntGenerator(int left_border, int right_border);

    IntGenerator operator=(const IntGenerator& rhs);

    int getNumber();

    int getNumber(int left_border, int right_border);

private:
    enum class DEFAULT {
        LEFT_BORDER = -10,
        RIGHT_BORDER = 10
    };

    int left_border_;
    int right_border_;
    static int randomizer_;
};

#endif // INTGENERATOR_H
