#ifndef THERMOMETER_CONST_H
#define THERMOMETER_CONST_H

class ThermometerConst
{
public:
    ThermometerConst(double temperature);
    double get_temperature();

private:
    double _temperature;
};

#endif
