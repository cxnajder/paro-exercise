#include "benchmark/benchmark.h"
#include "scrabbleScore.h"

static const int cIterations = 1 << 20;


// CABAGE

static void scrabble_CABBAGE_CX(benchmark::State &s)
{
    for (auto _ : s)
    {
        cxnajdersCode::countScrabbleScore("CABBAGE");
    }
}
static void scrabble_CABBAGE_BRONKO(benchmark::State &s)
{
    for (auto _ : s)
    {
        bronkosCode::countScrabbleScore("CABBAGE");
    }
}

BENCHMARK(scrabble_CABBAGE_CX)->Iterations(cIterations);
BENCHMARK(scrabble_CABBAGE_BRONKO)->Iterations(cIterations);

// cabage

static void scrabble_cabage_CX(benchmark::State &s)
{
    for (auto _ : s)
    {
        cxnajdersCode::countScrabbleScore("cabbage");
    }
}
static void scrabble_cabage_BRONKO(benchmark::State &s)
{
    for (auto _ : s)
    {
        bronkosCode::countScrabbleScore("cabbage");
    }
}

BENCHMARK(scrabble_cabage_CX)->Iterations(cIterations);
BENCHMARK(scrabble_cabage_BRONKO)->Iterations(cIterations);

// CABAGE -- DoNotOptimize

static void scrabble_CABBAGE_DoNotOptimize_CX(benchmark::State &s)
{
    for (auto _ : s)
    {
        benchmark::DoNotOptimize(cxnajdersCode::countScrabbleScore("CABBAGE"));
    }
}
static void scrabble_CABBAGE_DoNotOptimize_BRONKO(benchmark::State &s)
{
    for (auto _ : s)
    {
        benchmark::DoNotOptimize(bronkosCode::countScrabbleScore("CABBAGE"));
    }
}

BENCHMARK(scrabble_CABBAGE_DoNotOptimize_CX)->Iterations(cIterations);
BENCHMARK(scrabble_CABBAGE_DoNotOptimize_BRONKO)->Iterations(cIterations);

// cabage -- DoNotOptimize

static void scrabble_cabage_DoNotOptimize_CX(benchmark::State &s)
{
    for (auto _ : s)
    {
         benchmark::DoNotOptimize(cxnajdersCode::countScrabbleScore("cabbage"));
    }
}
static void scrabble_cabage_DoNotOptimize_BRONKO(benchmark::State &s)
{
    for (auto _ : s)
    {
         benchmark::DoNotOptimize(bronkosCode::countScrabbleScore("cabbage"));
    }
}

BENCHMARK(scrabble_cabage_DoNotOptimize_CX)->Iterations(cIterations);
BENCHMARK(scrabble_cabage_DoNotOptimize_BRONKO)->Iterations(cIterations);

//

BENCHMARK_MAIN();