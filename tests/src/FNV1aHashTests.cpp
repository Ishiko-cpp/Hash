/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/hash/blob/main/LICENSE.txt
*/

#include "FNV1aHashTests.h"
#include "Ishiko/Hash/FNV1aHash.h"

using namespace Ishiko;
using namespace Ishiko::Hash;

FNV1aHashTests::FNV1aHashTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "FNV1aHash tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("update test 1", UpdateTest1);
    append<HeapAllocationErrorsTest>("update test 2", UpdateTest2);
    append<HeapAllocationErrorsTest>("update test 3", UpdateTest3);
}

void FNV1aHashTests::ConstructorTest1(Test& test)
{
    FNV1aHash hash;

    ISHIKO_TEST_FAIL_IF_NEQ(hash.value(), 0xcbf29ce484222325ULL);
    ISHIKO_TEST_PASS();
}

void FNV1aHashTests::UpdateTest1(Test& test)
{
    FNV1aHash hash;

    hash.update("a", 1);

    ISHIKO_TEST_FAIL_IF_NEQ(hash.value(), 0xaf63dc4c8601ec8cULL);
    ISHIKO_TEST_PASS();
}

void FNV1aHashTests::UpdateTest2(Test& test)
{
    FNV1aHash hash;

    hash.update("The quick brown fox jumps over the lazy dog", 43);

    ISHIKO_TEST_FAIL_IF_NEQ(hash.value(), 0xf3f9b7f5e7e47110ULL);
    ISHIKO_TEST_PASS();
}

void FNV1aHashTests::UpdateTest3(Test& test)
{
    FNV1aHash hash;

    std::string data = "The quick brown fox jumps over the lazy dog";
    hash.update(data);

    ISHIKO_TEST_FAIL_IF_NEQ(hash.value(), 0xf3f9b7f5e7e47110ULL);
    ISHIKO_TEST_PASS();
}
