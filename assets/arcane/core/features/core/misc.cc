#include "misc.hh"

namespace arcane::core::features {
	void auto_bunny_hop( sdk::ifaces::user_cmd* cmd ) {
		if ( !menu::checkbox[ "#auto_bunny_hop_checkbox" ]->get_bool( ) )
			return;

		static auto local_player = ifaces::get_ifaces.client_entity->get_client_entity( ifaces::get_ifaces.engine->get_local_player( ) );

		if ( !local_player )
			return;

		if ( !( local_player->get_health( ) > 0 ) )
			return;

		if ( cmd->buttons & CONV_ENUM_TYPE( std::int32_t, sdk::enums::button::button_jump ) && !( local_player->get_flags( ) & CONV_ENUM_TYPE( std::int32_t, sdk::enums::flags::flags_on_ground ) ) )
			cmd->buttons &= ~CONV_ENUM_TYPE( std::int32_t, sdk::enums::button::button_jump );
	}

	void rank_revealer( ) {
		if ( !menu::checkbox[ "#rank_revealer_checkbox" ]->get_bool( ) )
			return;

		ifaces::get_ifaces.base_client->dispatch_user_message( 50, 0, 0, nullptr );
	}

	void disconnect_to_lobby( ) {
		if ( ifaces::get_ifaces.engine->is_connected( ) && ifaces::get_ifaces.engine->is_in_game( ) ) {
			ifaces::get_ifaces.base_client->dispatch_user_message( 35, 0, 0, nullptr );

			fgui::handler::call_notification( "disconnected to lobby!", fgui::animation_type::LINEAR );
		} else
			fgui::handler::call_notification( "you must be in game first!", fgui::animation_type::LINEAR );
	}
}
