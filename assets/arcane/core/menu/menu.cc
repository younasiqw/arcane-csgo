#include "menu.hh"

namespace arcane::core::menu {
	void menu_setup( ) {
		const fgui::element_font menu_font = { "Tahoma", 12, fgui::external::font_flags::SHADOW, false };

		// https://www.dafont.com/heydings-icons.font
		const fgui::element_font icon_font = { "Heydings Icons", 48, fgui::external::font_flags::ANTIALIAS, false };

		ADD_WINDOW( container[ "#window" ], 200, 200, "arcane", 718, 454, fgui::external::KEY_INSERT, menu_font, false );
		REGISTER_CURSOR( fgui::cursor_type::NONE, fgui::input_state::UNLOCKED );
		REGISTER_TAB( tabs[ "#tab_panel" ], 6, 2, fgui::tab_layout::VERTICAL, icon_font, container[ "#window" ], -1 );

		static std::int32_t screen_width, screen_height;

		fgui::render.get_screen_size( screen_width, screen_height );

		REGISTER_NOTIFICATIONS( screen_width, screen_height / 2, menu_font );

		ADD_TAB( tabs[ "#tab_panel" ], "y" ); {
			ADD_GROUPBOX( container[ "#players_groupbox" ], 168, 14, "players (enemies)", 260, 398, menu_font, container[ "#window" ], 0, false, false, false );
			ADD_CONTROLLER( container[ "#players_groupbox" ], tabs[ "#tab_panel" ] );
			ADD_CHECKBOX( checkbox[ "#player_visuals_enabled_checkbox" ], 8, 14, "enabled", "vars.player_visuals_enabled", menu_font, container[ "#players_groupbox" ], 0 );
			ADD_CHECKBOX( checkbox[ "#player_name_checkbox" ], 8, 32, "name", "vars.player_name", menu_font, container[ "#players_groupbox" ], 0 );
			ADD_CHECKBOX( checkbox[ "#player_health_checkbox" ], 8, 50, "health", "vars.player_health", menu_font, container[ "#players_groupbox" ], 0 );
			ADD_CHECKBOX( checkbox[ "#player_armor_checkbox" ], 8, 68, "armor", "vars.player_armor", menu_font, container[ "#players_groupbox" ], 0 );
			ADD_CHECKBOX( checkbox[ "#player_scoped_check_checkbox" ], 8, 86, "scoped check", "vars.scoped_check", menu_font, container[ "#players_groupbox" ], 0 );
			ADD_GROUPBOX( container[ "#world_groupbox" ], 440, 14, "world", 260, 398, menu_font, container[ "#window" ], 0, false, false, false );
			ADD_CONTROLLER( container[ "#world_groupbox" ], tabs[ "#tab_panel" ] );
			ADD_CHECKBOX( checkbox[ "#flash_alpha_checkbox" ], 8, 14, "flash alpha", "vars.flash_alpha", menu_font, container[ "#world_groupbox" ], 0 );
			ADD_SLIDER( slider[ "#flash_alpha_slider" ], 8, 50, "flash alpha slider", 0.0f, 0.0f, 255.0f, "vars.flash_alpha_slider", menu_font, container[ "#world_groupbox" ], 0 );
			ADD_CHECKBOX( checkbox[ "#view_model_fov_checkbox" ], 8, 78, "view model fov", "vars.view_model_fov", menu_font, container[ "#world_groupbox" ], 0 );
			ADD_SLIDER( slider[ "#view_model_fov_slider" ], 8, 114, "view model fov slider", 0.0f, 0.0f, 68.0f, "vars.view_model_fov_slider", menu_font, container[ "#world_groupbox" ], 0 );
		}

		ADD_TAB( tabs[ "#tab_panel" ], "G" ); {
			ADD_GROUPBOX( container[ "#main_groupbox" ], 168, 14, "main", 260, 398, menu_font, container[ "#window" ], 1, false, false, false );
			ADD_CONTROLLER( container[ "#main_groupbox" ], tabs[ "#tab_panel" ] );
			ADD_CHECKBOX( checkbox[ "#auto_bunny_hop_checkbox" ], 8, 14, "auto bunny hop", "vars.auto_bunny_hop", menu_font, container[ "#main_groupbox" ], 1 );
			ADD_CHECKBOX( checkbox[ "#rank_revealer_checkbox" ], 8, 32, "rank revealer", "vars.rank_revealer", menu_font, container[ "#main_groupbox" ], 1 );
			ADD_CHECKBOX( checkbox[ "#grenade_preview_checkbox" ], 8, 50, "grenade preview", "vars.grenade_preview", menu_font, container[ "#main_groupbox" ], 1 );
			ADD_BUTTON( button[ "#disconnect_to_lobby_button" ], 8, 78, "disconnect to lobby", 110, 20, menu_font, container[ "#main_groupbox" ], 1 );
			ADD_FUNCTION( button[ "#disconnect_to_lobby_button" ], features::disconnect_to_lobby );
			ADD_GROUPBOX( container[ "#other_groupbox" ], 440, 14, "other", 260, 398, menu_font, container[ "#window" ], 1, false, false, false );
			ADD_CONTROLLER( container[ "#other_groupbox" ], tabs[ "#tab_panel" ] );
			ADD_CHECKBOX( checkbox[ "#watermark_checkbox" ], 8, 14, "watermark", "vars.watermark", menu_font, container[ "#other_groupbox" ], 1 );
			ADD_CHECKBOX( checkbox[ "#unload_cheat_checkbox" ], 8, 32, "unload cheat", "vars.unload_cheat", menu_font, container[ "#other_groupbox" ], 1 );
		}

		ADD_TAB( tabs[ "#tab_panel" ], "Z" ); {
			ADD_GROUPBOX( container[ "#save_load_groupbox" ], 168, 14, "save/load", 260, 198, menu_font, container[ "#window" ], 2, false, false, false );
			ADD_CONTROLLER( container[ "#save_load_groupbox" ], tabs[ "#tab_panel" ] );
			ADD_BUTTON( button[ "#save_config_button" ], 8, 14, "save cfg", 110, 20, menu_font, container[ "#save_load_groupbox" ], 2 );
			ADD_FUNCTION( button[ "#save_config_button" ], features::save_cfg );
			ADD_BUTTON( button[ "#load_config_button" ], 8, 38, "load cfg", 110, 20, menu_font, container[ "#save_load_groupbox" ], 2 );
			ADD_FUNCTION( button[ "#load_config_button" ], features::load_cfg );
		}
	}
}
