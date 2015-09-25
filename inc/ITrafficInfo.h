// Traffic information interface for FS2004 SDK
// Copyright (C) Microsoft Corporation 2003. All rights reserved.

#ifndef _TrafficInfo_h_
#define _TrafficInfo_h_

static CHAR TRAFFIC_INFO_INTERFACE_NAME[] = "ITrafficInfo";

class ITrafficInfo : public IPanelCCallback
{
public:

    //
    // IPanelCCallback methods
    //
    virtual IPanelCCallback* QueryInterface (PCSTRINGZ pszInterface) = 0;
    virtual UINT32 GetVersion () = 0;
    virtual IAircraftCCallback*  CreateAircraftCCallback (UINT32 ContainerID) = 0;
    virtual bool  ConvertStringToProperty (PCSTRINGZ keyword, SINT32* pID) = 0;
    virtual bool  ConvertPropertyToString (SINT32 id, PPCSTRINGZ pKeyword) = 0;
    virtual bool  GetPropertyUnits (SINT32 id, ENUM* pEnum) = 0;            // UNITS_UNKNOWN if no units, UNITS_STRING if string

    //
    // ITrafficInfo methods
    //

    // query for the id of a named aircraft variable
    virtual ENUM QueryAircraftVarEnum(
        PCSTRINGZ pszAircraftVar    // in: name of the aircraft variable
        ) const = 0;

    // query for the id of a named unit of measure
    virtual ENUM QueryUnitEnum(
        PCSTRINGZ pszUnit           // in: name of the unit of measure
        ) const = 0;

    // query for a list of aircraft near the user aircraft (includes user aircraft)
    // returns the number of aircraft found by the query
    virtual UINT32 QueryAircraftNearUser(
        FLOAT64 dRadiusMeters,      // in: query radius in meters
        UINT32  uMaxAircraftIds,    // in: maximum number of aircraft ids to return in puAircraftIds
        UINT32* puAircraftIds       // out: array of aircraft ids within the query radius
        ) const = 0;

    // query for a list of aircraft near an arbitrary point (includes user aircraft)
    // returns the number of aircraft found by the query
    virtual UINT32 QueryAircraftNearPoint(
        FLOAT64 dLatitudeDegrees,   // in: query center point latitude in degrees
        FLOAT64 dLongitudeDegrees,  // in: query center point longitude in degrees
        FLOAT64 dAltitudeMeters,    // in: query center point true altitude in meters
        FLOAT64 dRadiusMeters,      // in: query radius in meters
        UINT32  uMaxAircraftIds,    // in: maximum number of aircraft ids to return in puAircraftIds
        UINT32* puAircraftIds       // out: array of aircraft ids within the query radius
        ) const = 0;

    // get the value of an aircraft floating point variable
    // returns true if successful
    virtual BOOL AircraftVarGetFloat(
        UINT32 uAircraftId,     // in: aircraft identifier
        ENUM simvar,            // in: variable id, obtained from QueryAircraftVarEnum()
        ENUM units,             // in: desired units for returned value, obtained from QueryUnitEnum()
        FLOAT64* pdValue,       // out: value
        SINT32 index = 0        // in: optional one-based array index for array variables
        ) const = 0;

    // get the value of an aircraft string variable
    // returns true if successful
    virtual BOOL AircraftVarGetString(
        UINT32 uAircraftId,     // in: aircraft identifier
        ENUM simvar,            // in: variable id, obtained from QueryAircraftVarEnum()
        PSTRINGZ pszBuffer,     // out: value string
        UINT32 uBufferLength,   // in: maximum length of pszBuffer
        SINT32 index = 0        // in: optional one-based array index for array variables
        ) const = 0;

    // get the name of the traffic database file from which this aircraft was instantiated
    // and the instance key which uniquely identifies the aircraft within the file
    virtual BOOL AircraftGetDatabaseInfo(
        UINT32 uAircraftId,     // in: aircraft identifier
        PSTRINGZ pszFileName,   // out: database file name buffer
        UINT32 uFileNameMax,    // in: max length of database file name buffer
        UINT32* puInstanceKey   // out: aircraft instance key
        ) const = 0;

    // return TRUE if a multiplayer session is active
    virtual BOOL IsMultiplayerActive() const = 0;

    // get the multiplayer name assigned to an aircraft
    // returns an empty string for non-multiplayer aircraft
    virtual PCSTRINGZ GetPlayerName(
        UINT32 uAircraftId      // in: aircraft identifier
        ) const = 0;
};

#endif // _TrafficInfo_h_
