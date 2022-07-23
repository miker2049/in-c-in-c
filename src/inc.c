#include "smf.h"

int main(int argc, char *argv[]) {
  smf_t *m;

  m = smf_new();
  smf_add_track(m, smf_track_new());
  smf_add_track(m, smf_track_new());
  smf_track_add_event_seconds(m->tracks_array->pdata[0], smf_event_new_from_bytes(144, 60, 127), 10.0);
  smf_track_add_event_seconds(m->tracks_array->pdata[0], smf_event_new_from_bytes(144, 60, 0), 18.0);
  printf("%f\n", 1.0/32.0);

  if(!smf_save(m, "testttttty.mid"))
      printf("look at that, we are done!\n");
  else
      printf("trouble saving\n");
  return 0;
}
