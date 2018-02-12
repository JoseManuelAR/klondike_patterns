#include "libview/console.hpp"

namespace view {
const std::string Console::DISABLE = "\033[30m";
const std::string Console::ENABLE = "\033[0m";
const std::string Console::RESET = "\033[0m";

const std::string Console::StringValue[] = {"A", "2", "3",  "4", "5", "6", "7",
                                            "8", "9", "10", "J", "Q", "K"};
const std::string Console::StringSuit[] = {"\xe2\x99\xa0", "\xe2\x99\xa3",
                                           "\xe2\x99\xa5", "\xe2\x99\xa6"};
const std::string Console::StringColor[] = {"\033[30m", "\033[31m"};
}