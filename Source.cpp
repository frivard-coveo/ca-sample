#include <chrono>

const char* TEST_DATA[] = { "The Hitchhiker's Guide to the Galaxy", "The Restaurant at the End of the Universe", "Life, the Universe and Everything" };
const size_t TEST_DATA_SIZE = sizeof(TEST_DATA) / sizeof(TEST_DATA[0]);

void DoSomething()
{
    unsigned int loopIndex = 0;
    const unsigned int endId = 8192;
    const auto testBegin = std::chrono::system_clock::now();
    const auto testDuration = std::chrono::seconds{ 10 };
    auto currentTime = std::chrono::system_clock::now();
    while (currentTime - testBegin < testDuration) {
        for (unsigned int id = (endId * loopIndex); id < (endId * (loopIndex + 1)); ++id) {
            auto index = id % TEST_DATA_SIZE;
            auto str = TEST_DATA[index];
            auto p = std::make_pair(id, 42);
        }
        ++loopIndex;
        currentTime = std::chrono::system_clock::now();
    }
}
