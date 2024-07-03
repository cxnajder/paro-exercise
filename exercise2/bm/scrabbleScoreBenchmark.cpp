#include "benchmark/benchmark.h"

static void cxnajderScrabbleBench(benchmark::State &s)
{
    for (auto _ : s)
    {
        //benchmark::DoNotOptimize();
    }
}
BENCHMARK(cxnajderScrabbleBench);
BENCHMARK_MAIN();