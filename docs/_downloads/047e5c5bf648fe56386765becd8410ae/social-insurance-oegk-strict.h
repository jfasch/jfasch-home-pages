#pragma once

#include "social-insurance-flexible-strict.h"

#include <iostream>
#include <map>


class OEGK : public SocialInsurance
{
public:
    virtual void charge(const std::string& id, double euros);
    virtual double debt(const std::string& id) const;

private:
    std::map<std::string, double> _database;

private:
    OEGK() : SocialInsurance("OEGK") {}
    friend class SocialInsurance;
};
