#pragma once

#include "../Component.h"
#include "../Pinouts/PinableIO.h"
namespace components
{
    class NonIOComponent : public Component
    {
    protected:
        int findIOComponent()
        {
            return findIOComponent(1);
        }
        //returns the index of the nth IO element
        int findIOComponent(int n);
    };
}
