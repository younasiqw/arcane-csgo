#include "main.hh"

namespace arcane::core::main {
	BOOL WINAPI detach( ) {
		hooks::hooks_destroy( );

		return TRUE;
	}

	DWORD WINAPI attach( const LPVOID thread ) {
		ifaces::ifaces { };
		mem::mem { };

		sdk::misc::get_netvar_tree = std::make_unique< sdk::misc::netvar_tree >( );
		sdk::misc::render_setup( );
		sdk::misc::input_helper_setup( );

		hooks::hooks_create( );

		menu::menu_setup( );

		fgui::handler::call_notification( "arcane has been loaded!", fgui::animation_type::LINEAR );

		while ( !menu::checkbox[ "#unload_cheat_checkbox" ]->get_bool( ) )
			std::this_thread::sleep_for( std::chrono::milliseconds( 50 ) );

		std::this_thread::sleep_for( std::chrono::milliseconds( 400 ) );

		detach( );

		FreeLibraryAndExitThread( static_cast< HMODULE >( thread ), EXIT_SUCCESS );
	}
}
