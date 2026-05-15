#include "NonIOComponent.h"
using namespace components;

int NonIOComponent::findIOComponent(int n)
{
    int count=0;
    for(int i=0;i<m_IO->size();i++)
    {
        if (dynamic_cast<PinableIO*>(m_IO->at(i)))
        {
            count++;
            if(count==n)
                return i;
        }
    }
    return -1;
}
