/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Hash/blob/main/LICENSE.txt
*/

#include "FNV1aHashTests.h"
#include "Ishiko/Hash/FNV1aHash.h"

using namespace Ishiko::Hash;
using namespace Ishiko::Tests;

FNV1aHashTests::FNV1aHashTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "FNV1aHash tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("update test 1", UpdateTest1);
    append<HeapAllocationErrorsTest>("update test 2", UpdateTest2);
}

void FNV1aHashTests::ConstructorTest1(Ishiko::Tests::Test& test)
{
    FNV1aHash hash;

    ISHTF_FAIL_IF_NEQ(hash.value(), 0xcbf29ce484222325ULL);
    ISHTF_PASS();
}

void FNV1aHashTests::UpdateTest1(Test& test)
{
    FNV1aHash hash;

    hash.update("a", 1);

    ISHTF_FAIL_IF_NEQ(hash.value(), 0xaf63dc4c8601ec8cULL);
    ISHTF_PASS();
}

void FNV1aHashTests::UpdateTest2(Test& test)
{
    FNV1aHash hash;

    hash.update("The quick brown fox jumps over the lazy dog", 43);

    ISHTF_FAIL_IF_NEQ(hash.value(), 0xf3f9b7f5e7e47110ULL);
    ISHTF_PASS();
}
