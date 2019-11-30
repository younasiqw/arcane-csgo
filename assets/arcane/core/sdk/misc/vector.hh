#pragma once

#include <cmath>
#include <algorithm>

namespace arcane::sdk::misc {
	// https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/mathlib/vector.h

	struct vector {
		float x, y, z;

		explicit vector( const float w = 0, const float h = 0, const float r = 0 ) {
			x = w;
			y = h;
			z = r;
		}

		vector operator+( const vector& point ) const {
			return vector( x + point.x, y + point.y, z + point.z );
		}

		vector operator-( const vector& point ) const {
			return vector( x - point.x, y - point.y, z - point.z );
		}

		vector operator*( const float point ) const {
			return vector( x * point, y * point, z * point );
		}

		vector& operator=( const float array[3] ) {
			x = array[ 0 ];
			y = array[ 1 ];
			z = array[ 2 ];

			return *this;
		}

		vector& operator+=( const vector& point ) {
			x += point.x;
			y += point.y;
			z += point.z;

			return *this;
		}

		vector& operator-=( const vector& point ) {
			x -= point.x;
			y -= point.y;
			z -= point.z;

			return *this;
		}

		vector& operator/=( const float division ) {
			x /= division;
			y /= division;
			z /= division;

			return *this;
		}

		void normalize( ) {
			x = std::isfinite( x ) ? std::remainderf( x, 360.0f ) : 0.0f;
			y = std::isfinite( y ) ? std::remainderf( y, 360.0f ) : 0.0f;
			z = 0.0f;
		}

		void clamp( ) {
			normalize( );

			x = std::clamp( x, -89.0f, 89.0f );
			y = std::clamp( y, -180.0f, 180.0f );
			z = 0.0f;
		}

		auto length( ) const {
			return std::sqrtf( x * x + y * y + z * z );
		}
	};
}
