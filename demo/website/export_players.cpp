#include <emscripten/bind.h>
#include "../../game.hpp"
#include "../../heuristics.hpp"
#include "../../strategies/ExpectimaxDepthStrategy.hpp"
#include "../../strategies/MinimaxStrategy.hpp"

using emscripten::class_;
using emscripten::function;

EMSCRIPTEN_BINDINGS(players) {
    class_<ExpectimaxDepthStrategy>("ExpectimaxDepthStrategy")
        .constructor<const int, const int>()
        .function("pick_move", &ExpectimaxDepthStrategy::pick_move);

    class_<MinimaxStrategy>("MinimaxStrategy")
        .constructor<const int, const int>()
        .function("pick_move", &MinimaxStrategy::pick_move);

    function("corner_heuristic", &heuristics::corner_heuristic);
}

