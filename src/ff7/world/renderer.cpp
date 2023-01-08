/****************************************************************************/
//    Copyright (C) 2009 Aali132                                            //
//    Copyright (C) 2018 quantumpencil                                      //
//    Copyright (C) 2018 Maxime Bacoux                                      //
//    Copyright (C) 2020 myst6re                                            //
//    Copyright (C) 2020 Chris Rizzitello                                   //
//    Copyright (C) 2020 John Pritchard                                     //
//    Copyright (C) 2022 Julian Xhokaxhiu                                   //
//    Copyright (C) 2022 Cosmos                                             //
//    Copyright (C) 2022 Tang-Tang Zhou                                     //
//                                                                          //
//    This file is part of FFNx                                             //
//                                                                          //
//    FFNx is free software: you can redistribute it and/or modify          //
//    it under the terms of the GNU General Public License as published by  //
//    the Free Software Foundation, either version 3 of the License         //
//                                                                          //
//    FFNx is distributed in the hope that it will be useful,               //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of        //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
//    GNU General Public License for more details.                          //
/****************************************************************************/

#include "renderer.h"

#include "../../renderer.h"

namespace ff7::world {

    void init_load_wm_bot_blocks() {
        ff7_externals.world_init_load_wm_bot_block_7533AF();
    }

    void wm0_overworld_draw_all() {
        ff7_externals.world_wm0_overworld_draw_all_74C179();
    }

    void wm2_underwater_draw_all() {
        ff7_externals.world_wm2_underwater_draw_all_74C3F0();
    }

    void wm3_snowstorm_draw_all() {
        ff7_externals.world_wm3_snowstorm_draw_all_74C589();
    }

    // This draw call is the first UI call that marks the start of the first UI draw section
    void wm0_draw_minimap_quad_graphics_object(ff7_graphics_object* quad_graphics_object, ff7_game_obj* game_object) {
        newRenderer.setTimeFilterEnabled(false);
        ff7_externals.engine_draw_graphics_object(quad_graphics_object, game_object);
    }

    // This draw call is the first call related to world effects. It marks the end of the first UI draw section
    void wm0_draw_world_effects_1_graphics_object(ff7_graphics_object* world_effects_1_graphics_object, ff7_game_obj* game_object) {
        newRenderer.setTimeFilterEnabled(true);
        ff7_externals.engine_draw_graphics_object(world_effects_1_graphics_object, game_object);
    }

    // This draw call is the UI call that marks the second UI draw section
    void wm0_draw_minimap_points_graphics_object(ff7_graphics_object* minimap_points_graphics_object, ff7_game_obj* game_object) {
        newRenderer.setTimeFilterEnabled(false);
        ff7_externals.engine_draw_graphics_object(minimap_points_graphics_object, game_object);
    }

}
