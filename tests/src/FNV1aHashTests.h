/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/hash/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_HASH_TESTS_FNV1AHASHTESTS_H_
#define _ISHIKO_CPP_HASH_TESTS_FNV1AHASHTESTS_H_

#include <Ishiko/TestFramework/Core.hpp>

class FNV1aHashTests : public Ishiko::TestSequence
{
public:
    FNV1aHashTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void UpdateTest1(Ishiko::Test& test);
    static void UpdateTest2(Ishiko::Test& test);
    static void UpdateTest3(Ishiko::Test& test);
};

#endif
