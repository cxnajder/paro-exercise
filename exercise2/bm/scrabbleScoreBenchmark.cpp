#include "benchmark/benchmark.h"
#include "scrabbleScore.h"

static void cxnajderScrabbleBench_cabbage(benchmark::State &s)
{
    for (auto _ : s)
    {
        benchmark::DoNotOptimize(cxnajdersCode::countScrabbleScore("cabbage"));
    }
}
static void cxnajderScrabbleBench_cabbage_optimal(benchmark::State &s)
{
    for (auto _ : s)
    {
        cxnajdersCode::countScrabbleScore("cabbage");
    }
}


//

static void cxnajderScrabbleBench_CABBAGE_optimal(benchmark::State &s)
{
    for (auto _ : s)
    {
        cxnajdersCode::countScrabbleScore("CABBAGE");
    }
}
static void bronkoScrabbleBench_CABBAGE_optimal(benchmark::State &s)
{
    for (auto _ : s)
    {
        bronkosCode::countScrabbleScore("CABBAGE");
    }
}

//


static void bronkoScrabbleBench_CABBAGE(benchmark::State &s)
{
    for (auto _ : s)
    {
        benchmark::DoNotOptimize(bronkosCode::countScrabbleScore("CABBAGE"));
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
BENCHMARK(cxnajderScrabbleBench_cabbage_optimal);

BENCHMARK(cxnajderScrabbleBench_CABBAGE);
BENCHMARK(bronkoScrabbleBench_CABBAGE);

BENCHMARK(cxnajderScrabbleBench_CABBAGE_optimal);
BENCHMARK(bronkoScrabbleBench_CABBAGE_optimal);

BENCHMARK_MAIN();