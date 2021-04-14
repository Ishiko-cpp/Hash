/*
    Copyright (c) 2017-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Hash/blob/main/LICENSE.txt
*/

#include <Ishiko/TestFramework/TestFrameworkCore.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoHash");

    theTestHarness.environment().setTestDataDirectory("../../TestData");
    theTestHarness.environment().setTestOutputDirectory("../../TestOutput");
    
    TestSequence& theTests = theTestHarness.tests();

    return theTestHarness.run();
}
