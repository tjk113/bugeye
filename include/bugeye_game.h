#ifndef BUGEYE_GAME_H
#define BUGEYE_GAME_H

#include "bn_regular_bg_ptr.h"
#include "bn_sprite_ptr.h"

#include "mj/mj_game.h"

namespace bugeye
{

class bug_game : public mj::game
{

public:
    bug_game(int completed_games, const mj::game_data& data);

    [[nodiscard]] bn::string<16> title() const final
    {
        return "BugEye";
    }

    [[nodiscard]] int total_frames() const final
    {
        return _total_frames;
    }

    void fade_in(const mj::game_data& data) final;

    [[nodiscard]] mj::game_result play(const mj::game_data& data) final;

    [[nodiscard]] bool victory() const final
    {
        return _victory;
    }

    void fade_out(const mj::game_data& data) final;

private:
    bn::regular_bg_ptr _bg;
    bn::sprite_ptr _bugeye;
    float _speed = 2.0f;
    int _total_frames;
    int _show_result_frames = 60;
    bool _victory = false;
    bool _defeat = false;
};

}

#endif
