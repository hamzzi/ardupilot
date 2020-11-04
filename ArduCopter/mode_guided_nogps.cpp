#include "Copter.h"

#if MODE_GUIDED_NOGPS_ENABLED == ENABLED

void ModeGuidedNoGPS::dump_state()
{
    FILE *fptr = fopen("state.txt","a");
    fprintf(fptr,"%d\n", (int)mode());
    fprintf(fptr,"%d %d\n", (int)motors->get_desired_spool_state(), (int)motors->get_spool_state());
    fclose(fptr);
}

/*
 * Init and run calls for guided_nogps flight mode
 */

// initialise guided_nogps controller
bool ModeGuidedNoGPS::init(bool ignore_checks)
{
    // start in angle control mode
    ModeGuided::angle_control_start();
    return true;
}

// guided_run - runs the guided controller
// should be called at 100hz or more
void ModeGuidedNoGPS::run()
{
    // run angle controller
    ModeGuided::angle_control_run();
}

#endif
