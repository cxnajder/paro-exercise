#include "benchmark/benchmark.h"
#include "scrabbleScore.h"

static void cxnajderScrabbleBench_cabbage(benchmark::State &s)
{
    for (auto _ : s)
    {
        benchmark::DoNotOptimize(cxnajdersCode::countScrabbleScore("cabbage"));
    }
}

static void cxnajderScrabbleBench_CABBAGE(benchmark::State &s)
{
    for (auto _ : s)
    {
        benchmark::DoNotOptimize(cxnajdersCode::countScrabbleScore("CABBAGE"));
    }
}
BENCHMARK(cxnajderScrabbleBench_cabbage);
BENCHMARK(cxnajderScrabbleBench_CABBAGE);
BENCHMARK_MAIN();