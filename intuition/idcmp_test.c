#include <intuition/intuition.h>
#include <exec/exec.h>

#include <proto/intuition.h>
#include <proto/exec.h>
#include <clib/alib_protos.h>

#include "idcmp.h"

int main(int argc, char **argv) {
  IDCMPEvents events;
  struct Window *window = OpenWindowTags(NULL,
    WA_Title, "Window",
    WA_Left, 10,
    WA_Top, 10,
    WA_Width, 500,
    WA_Height, 150,
    WA_IDCMP, ALL_IDCMP_EVENTS,
    WA_Flags, WFLGS_STD_WINDOW_V39,
    TAG_END
  );
  
  InitializeIDCMPEvents(&events);
  ApplyIDCMPBasics(&events);
  HandleIDCMP(&events, window, FALSE);
  
  return 0;
}