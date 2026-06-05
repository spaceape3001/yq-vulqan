////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/typedef/vector1.hpp>
#include <yq/typedef/vector2.hpp>
#include <yq/typedef/vector3.hpp>
#include <yq/typedef/vector4.hpp>
#include <yq/unit/declare.hpp>

namespace yq::tachyon::engine {

    double          to_screen(Meter);
    double          to_screen(Centimeter);
    double          to_screen(Foot);
    double          to_screen(Inch);
    double          to_screen(Kilometer);
    
    Vector1D        to_screen(const Centimeter1D&);
    Vector2D        to_screen(const Centimeter2D&);
    Vector3D        to_screen(const Centimeter3D&);
    Vector4D        to_screen(const Centimeter4D&);

    Vector1D        to_screen(const Foot1D&);
    Vector2D        to_screen(const Foot2D&);
    Vector3D        to_screen(const Foot3D&);
    Vector4D        to_screen(const Foot4D&);

    Vector1D        to_screen(const Inch1D&);
    Vector2D        to_screen(const Inch2D&);
    Vector3D        to_screen(const Inch3D&);
    Vector4D        to_screen(const Inch4D&);

    Vector1D        to_screen(const Kilometer1D&);
    Vector2D        to_screen(const Kilometer2D&);
    Vector3D        to_screen(const Kilometer3D&);
    Vector4D        to_screen(const Kilometer4D&);

    Vector1D        to_screen(const Meter1D&);
    Vector2D        to_screen(const Meter2D&);
    Vector3D        to_screen(const Meter3D&);
    Vector4D        to_screen(const Meter4D&);


    Centimeter      to_centimeter(double);
    Centimeter1D    to_centimeter(const Vector1D&);
    Centimeter2D    to_centimeter(const Vector2D&);
    Centimeter3D    to_centimeter(const Vector3D&);
    Centimeter4D    to_centimeter(const Vector4D&);


    Kilometer   to_kilometer(double);
    Foot        to_foot(double);
    Inch        to_inch(double);
    Meter       to_meter(double);
    
    
}
