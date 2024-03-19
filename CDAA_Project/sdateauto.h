#ifndef SDATEAUTO_H
#define SDATEAUTO_H

#include <chrono>
#include <iostream>
#include <string>

#include "date/date.h"
#include "date/chrono_io.h"

using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;
using namespace std;

/**
 * @struct sdateAuto
 * @brief Structure pour représenter une date au format "jj/mm/aaaa".
 */
struct sdateAuto {
        day jour;///< Jour de la date.
        month mois;///< Mois de la date.
        year annee;///< Année de la date.
};
#endif // SDATEAUTO_H
