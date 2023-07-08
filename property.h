#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

// Property object representing an individual property object from the Alachua County data

/* Object attribute (class) and CSV data equivalent (column)
 * ======================================================================
 * attribute = Column Equivalent
 * marketValue = JV (Column K)
 * zipCode = PHY_ZIPCD (Column CX)
 * yearBuilt = EFF_YR_BLT (Column AV)
 * address = PHY_ADDR1 (Column CU
 * city = PHY_CITY (Column CW)
 * ----------------------------------------------------------------------
 * propertyType (special case)
 * Column H - DOR_UC
 * 01-09 Residential
 * Any other numbers above 09 and to 099 are non-residential.
 * See: Page 5 of the user guide.
 * ----------------------------------------------------------------------
 * More exact details and information in the user guide.
 */
class Property
{
    int marketValue;
    int zipCode;
    int yearBuilt;
    std::string address;
    std::string city;
    std::string propertyType;

public:
    Property(int MARKETVALUE, int ZIPCODE, int YEARBUILT, std::string ADDRESS, std::string CITY, std::string PROPERTYTYPE)
        : marketValue(MARKETVALUE), zipCode(ZIPCODE), yearBuilt(YEARBUILT), address(ADDRESS), city(CITY), propertyType(PROPERTYTYPE){};

    int getMarketValue() const;

    void setMarketValue(int newMarketValue);

    int getZipCode() const;

    void setZipCode(int newZipCode);

    int getYearBuilt() const;

    void setYearBuilt(int newYearBuilt);

    std::string getAddress() const;

    void setAddress(const std::string &newAddress);

    std::string getCity() const;

    void setCity(const std::string &newCity);

    std::string getPropertyType() const;

    void setPropertyType(const std::string &newPropertyType);
};

#endif // PROPERTY_H
