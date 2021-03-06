/*
 * PigsEvent.h
 * Class to hold the measurement information
 * Four channel version
 *
 *  Created on: Jun 26, 2015
 *      Author: Ondrej Chvala <ochvala@utk.edu>
 */

#ifndef PIGSEVENT_H
#define PIGSEVENT_H

#include <stdint.h>
#include <iostream>
#include <string>
#include <TObject.h>
#include <TH1F.h>

class PigsEvent : public TObject {
public:
    PigsEvent();
    virtual ~PigsEvent();
    virtual void Print(Option_t *option="") const;  // Prints the event information to stdout
    const char* GetMeasurementDate() const;         // Gets date of the measurement

    TH1F    *spectrum[4];           // Spectrum collected by the four detectors
    uint64_t realTime[4];           // Real time from DAQ [ns]
    uint64_t deadTime[4];           // Dead time from DAQ [ns]
    uint32_t goodCounts[4];         // Counts as measured by DAQ
    uint32_t totCounts[4];          // DAQ counts scaled up by (1+deadTime)/realTime
    Float_t  countsPerSecond[4];    // goodCounts/(realTime-deadTime)
    Float_t  scaleFactor[4];        // Scaling of the integral
    Float_t  detectorResponse[4];   // Signals used to calculate the arrow pointing angle

    Float_t  acqTime;               // Acquisition time set by DAQ
    Float_t  arrowAngle;            // Angle of the arrow as calculated by the fuzzy logic algorithm

    ClassDef(PigsEvent, 1)
};

#endif /* PIGSEVENT_H_ */
