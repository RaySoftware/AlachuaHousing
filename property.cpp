#include "property.h"

int Property::getMarketValue() const
{
    return marketValue;
}

void Property::setMarketValue(int newMarketValue)
{
    marketValue = newMarketValue;
}

int Property::getZipCode() const
{
    return zipCode;
}

void Property::setZipCode(int newZipCode)
{
    zipCode = newZipCode;
}

int Property::getYearBuilt() const
{
    return yearBuilt;
}

void Property::setYearBuilt(int newYearBuilt)
{
    yearBuilt = newYearBuilt;
}

std::string Property::getAddress() const
{
    return address;
}

void Property::setAddress(const std::string &newAddress)
{
    address = newAddress;
}

std::string Property::getCity() const
{
    return city;
}

void Property::setCity(const std::string &newCity)
{
    city = newCity;
}

std::string Property::getPropertyType() const
{
    return propertyType;
}

void Property::setPropertyType(const std::string &newPropertyType)
{
    propertyType = newPropertyType;
}
