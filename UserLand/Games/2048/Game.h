/*
 * Copyright (c) 2021, Krisna Pranav
 *
 * SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

// includes
#include <AK/Vector.h>

class Game final {
public:
    Game(size_t grid_size, size_t target_tile, bool evil_ai);
    Game(const Game&) = default;
    Game& operator=(const Game&) = default;

    enum class MoveOutcome {
        OK,
        InvalidMove,
        GameOver,
        Won,
    };

    enum class Direction {
        Up,
        Down,
        Left,
        Right,
    };

    MoveOutcome attempt_move(Direction);

    size_t score() const { return m_score; }
    size_t turns() const { return m_turns; }
    u32 target_tile() const { return m_target_tile; }
    u32 largest_tile() cosnt;

}