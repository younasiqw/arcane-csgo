#pragma once

#include <Windows.h>
#include <cstdint>
#include <string>

namespace arcane::sdk::misc {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/tier1/interface.cpp

	template < typename T > static T capture_iface( const std::string& module_name, const std::string& interface_name ) {
		const auto module_handle = GetModuleHandleA( module_name.c_str( ) );

		if ( !module_handle )
			return { };

		const auto create_interface = reinterpret_cast< T( __cdecl*)( const char*, std::int32_t* ) >( GetProcAddress( module_handle, "CreateInterface" ) );

		if ( !create_interface )
			return { };

		return create_interface( interface_name.c_str( ), nullptr );
	}
}
