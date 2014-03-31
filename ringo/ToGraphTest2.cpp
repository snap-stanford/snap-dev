#include "Snap.h"
#include <cstring>
#include <ctime>

int main(int argc, char** argv){

  if (argc != 2) {
    printf("usage: ./ToGraphTest2 [path-to-edge-list]\n");
    return 1;
  }

  printf("%s\n", argv[1]);

  TTableContext Context;

  struct timeval start, end;
  float delta;
  TTmProfiler Profiler;
  int TimerId = Profiler.AddTimer("Profiler");

  Schema S;
  S.Add(TPair<TStr,TAttrType>("src", atInt));
  S.Add(TPair<TStr,TAttrType>("dst", atInt));
  TIntV RelevantCols; RelevantCols.Add(0); RelevantCols.Add(1);

  Profiler.ResetTimer(TimerId);
  Profiler.StartTimer(TimerId);
  gettimeofday(&start, NULL);
  TFIn FIn(paths[GRAPH]);
  PTable Q = TTable::LoadSS("Graph", S, argv[1], Context, RelevantCols);

  Profiler.StopTimer(TimerId);
  gettimeofday(&end, NULL);
  delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
            end.tv_usec - start.tv_usec) / 1.e6;
  printf("Load time (elapsed): %f, cpu: %f\n", delta, Profiler.GetTimerSec(TimerId));

  TVec<TPair<TStr, TAttrType> > Schema = Q->GetSchema();

  
  Profiler.ResetTimer(TimerId);
  Profiler.StartTimer(TimerId);
  gettimeofday(&start, NULL);

  PNGraphMP G;
  G = TSnap::ToGraphMP2<PNGraphMP>(Q, Schema[0].GetVal1(), Schema[1].GetVal1());

  Profiler.StopTimer(TimerId);
  gettimeofday(&end, NULL);
  delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
            end.tv_usec - start.tv_usec) / 1.e6;

  printf("ToPNGraphMP time (elapsed): %f, cpu: %f\n", delta, Profiler.GetTimerSec(TimerId));

  return 0;
}
