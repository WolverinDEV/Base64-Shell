//
// Created by wolverindev on 22.04.17.
//

#pragma once

#include <string>

namespace Dump {
    namespace Hex {
        extern void dump(void *addr, int length, int numLength = 16, void (*)(char*) = printf);
    }
}