#pragma once
#include "Nucleon.h"
class Proton :
    public Nucleon
{
public:
    double getCharge() override;
};

