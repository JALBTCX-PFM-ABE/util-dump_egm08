
/*********************************************************************************************

    This is public domain software that was developed by or for the U.S. Naval Oceanographic
    Office and/or the U.S. Army Corps of Engineers.

    This is a work of the U.S. Government. In accordance with 17 USC 105, copyright protection
    is not available for any work of the U.S. Government.

    Neither the United States Government, nor any employees of the United States Government,
    nor the author, makes any warranty, express or implied, without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, or assumes any liability or
    responsibility for the accuracy, completeness, or usefulness of any information,
    apparatus, product, or process disclosed, or represents that its use would not infringe
    privately-owned rights. Reference herein to any specific commercial products, process,
    or service by trade name, trademark, manufacturer, or otherwise, does not necessarily
    constitute or imply its endorsement, recommendation, or favoring by the United States
    Government. The views and opinions of authors expressed herein do not necessarily state
    or reflect those of the United States Government, and shall not be used for advertising
    or product endorsement purposes.

*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "nvutility.h"

#include "version.h"


int32_t main (int32_t argc, char *argv[])
{
  double lat, lon;
  float value;


  printf ("\n\n %s \n\n", VERSION);


  if (argc < 3)
    {
      fprintf (stderr, "\nUsage: %s Latitude Longitude\n\n", argv[0]);
      fprintf (stderr, "Where:\n");
      fprintf (stderr, "\tLatitude and Longitude can be in any of the following formats:\n");
      fprintf (stderr, "\tHemisphere Degrees Minutes Seconds.decimal\n");
      fprintf (stderr, "\tHemisphere Degrees Minutes.decimal\n");
      fprintf (stderr, "\tHemisphere Degrees.decimal\n");
      fprintf (stderr, "\tSignDegrees Minutes Seconds.decimal\n");
      fprintf (stderr, "\tSignDegrees Minutes.decimal\n");
      fprintf (stderr, "\tSignDegrees.decimal\n\n");
      fprintf (stderr, "\tIf you use formats with spaces then the argument must be enclosed\n");
      fprintf (stderr, "\tin quotation marks (\")\n\n");
      fprintf (stderr, "\tExample: %s \"6 55.268\" \"122 3.575\"\n\n", argv[0]);
      exit (-1);
    }

  posfix (argv[1], &lat, POS_LAT);
  posfix (argv[2], &lon, POS_LON);


  value = get_egm08 (lat, lon);

  printf ("\n\nLat: %12.7f    Lon: %12.7f   Value: %f\n\n", lat, lon, value);

  return (0);
}
