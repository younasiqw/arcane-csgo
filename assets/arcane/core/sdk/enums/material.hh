#pragma once

namespace arcane::sdk::enums {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/mp/src/public/materialsystem/imaterial.h

	enum struct material {
		material_debug = 1 << 0,
		material_no_debug_override = 1 << 1,
		material_no_draw = 1 << 2,
		material_use_in_fillrate_mode = 1 << 3,
		material_vertex_color = 1 << 4,
		material_vertex_alpha = 1 << 5,
		material_selfillum = 1 << 6,
		material_additive = 1 << 7,
		material_alpha_test = 1 << 8,
		material_multi_pass = 1 << 9,
		material_z_nearer = 1 << 10,
		material_model = 1 << 11,
		material_flat = 1 << 12,
		material_no_cull = 1 << 13,
		material_no_fog = 1 << 14,
		material_ignorez = 1 << 15,
		material_decal = 1 << 16,
		material_env_map_sphere = 1 << 17,
		material_no_alpha_mod = 1 << 18,
		material_env_map_cameraspace = 1 << 19,
		material_basealphaenvmapmask = 1 << 20,
		material_translucent = 1 << 21,
		material_normal_map_alpha_env_map_mask = 1 << 22,
		material_needs_software_skinning = 1 << 23,
		material_opaque_texture = 1 << 24,
		material_env_map_mode = 1 << 25,
		material_suppress_decals = 1 << 26,
		material_half_lambert = 1 << 27,
		material_wireframe = 1 << 28,
		material_allow_alphato_coverage = 1 << 29,
		material_ignore_alpha_modulation = 1 << 30
	};
}
