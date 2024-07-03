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

static void bronkoScrabbleBench_CABBAGE_optimal(benchmark::State &s)
{
    for (auto _ : s)
    {
        bronkosCode::countScrabbleScore("CABBAGE");
    }
}

static void bronkoScrabbleBench_CABBAGE(benchmark::State &s)
{
    for (auto _ : s)
    {
        benchmark::DoNotOptimize(bronkosCode::countScrabbleScore("CABBAGE"));
    }
}


BENCHMARK(cxnajderScrabbleBench_cabbage);
BENCHMARK(cxnajderScrabbleBench_CABBAGE);
BENCHMARK(bronkoScrabbleBench_CABBAGE_optimal);
BENCHMARK(bronkoScrabbleBench_CABBAGE);
BENCHMARK_MAIN();