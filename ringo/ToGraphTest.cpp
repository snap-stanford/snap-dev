#include "Snap.h"
#include <cstring>
#include <ctime>

int main(int argc, char** argv){
  TTableContext Context;

  if (argc >= 2){
    strcpy(paths[GRAPH], argv[1]);
  }
  struct timeval start, end;
  float delta;
  TTmProfiler Profiler;
  int TimerId = Profiler.AddTimer("Profiler");

  Profiler.ResetTimer(TimerId);
  Profiler.StartTimer(TimerId);
  gettimeofday(&start, NULL);
  TFIn FIn(paths[GRAPH]);
  PTable Q = TTable::Load(FIn, Context);
  Profiler.StopTimer(TimerId);
  gettimeofday(&end, NULL);
  delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
            end.tv_usec - start.tv_usec) / 1.e6;
  printf("Load time (elapsed): %f, cpu: %f\n", delta, Profiler.GetTimerSec(TimerId));
  
  TVec<TPair<TStr, TAttrType> > Schema = Q->GetSchema();


  Profiler.ResetTimer(TimerId);
  Profiler.StartTimer(TimerId);
  gettimeofday(&start, NULL);

  PNGraphMP G4;
  if (CONVERSION_ALGO == ALGO_ONE) {
   G4 = TSnap::ToGraphMP<PNGraphMP>(Q, Schema[0].GetVal1(), Schema[1].GetVal1());
  }
  else {
   G4 = TSnap::ToGraphMP2<PNGraphMP>(Q, Schema[0].GetVal1(), Schema[1].GetVal1());
  }
  Profiler.StopTimer(TimerId);
  gettimeofday(&end, NULL);
  delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
            end.tv_usec - start.tv_usec) / 1.e6;

  printf("ToPNGraphMP time (elapsed): %f, cpu: %f\n", delta, Profiler.GetTimerSec(TimerId));
  return 0;
}
