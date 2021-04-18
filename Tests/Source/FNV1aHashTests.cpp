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
}

void FNV1aHashTests::ConstructorTest1(Ishiko::Tests::Test& test)
{
    FNV1aHash hash;

    ISHTF_PASS();
}
