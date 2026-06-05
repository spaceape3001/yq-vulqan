////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/engine.hpp>
#include <yq/tachyon/screen.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/vector/Vector4.hpp>
#include <yq/units.hpp>

namespace yq::tachyon::engine {
    extern LengthUnit  gLengthUnit;

    double      to_screen(Meter v)
    {
        switch(gLengthUnit){
        case LengthUnit::Centimeter:
            return Centimeter(v).value;
        case LengthUnit::Foot:
            return Foot(v).value;
        case LengthUnit::Inch:
            return Inch(v).value;
        case LengthUnit::Kilometer:
            return Kilometer(v).value;
        case LengthUnit::Meter:
            return v.value;
        default:
            return v.value;
        }
    }
    
    double      to_screen(Centimeter v)
    {
        switch(gLengthUnit){
        case LengthUnit::Centimeter:
            return v.value;
        case LengthUnit::Foot:
            return Foot(v).value;
        case LengthUnit::Inch:
            return Inch(v).value;
        case LengthUnit::Kilometer:
            return Kilometer(v).value;
        case LengthUnit::Meter:
            return Meter(v).value;
        default:
            return v.value;
        }
    }
    
    double      to_screen(Foot v)
    {
        switch(gLengthUnit){
        case LengthUnit::Centimeter:
            return Centimeter(v).value;
        case LengthUnit::Foot:
            return v.value;
        case LengthUnit::Inch:
            return Inch(v).value;
        case LengthUnit::Kilometer:
            return Kilometer(v).value;
        case LengthUnit::Meter:
            return Meter(v).value;
        default:
            return v.value;
        }
    }
    
    double      to_screen(Inch v)
    {
        switch(gLengthUnit){
        case LengthUnit::Centimeter:
            return Centimeter(v).value;
        case LengthUnit::Foot:
            return Foot(v).value;
        case LengthUnit::Inch:
            return v.value;
        case LengthUnit::Kilometer:
            return Kilometer(v).value;
        case LengthUnit::Meter:
            return Meter(v).value;
        default:
            return v.value;
        }
    }
    
    double      to_screen(Kilometer v)
    {
        switch(gLengthUnit){
        case LengthUnit::Centimeter:
            return Centimeter(v).value;
        case LengthUnit::Foot:
            return Foot(v).value;
        case LengthUnit::Inch:
            return Inch(v).value;
        case LengthUnit::Kilometer:
            return v.value;
        case LengthUnit::Meter:
            return Meter(v).value;
        default:
            return v.value;
        }
    }
    

    Vector1D    to_screen(const Centimeter1D&v)
    {
        return Vector1D(to_screen(v.x));
    }
    
    Vector2D    to_screen(const Centimeter2D&v)
    {
        return Vector2D(to_screen(v.x), to_screen(v.y));
    }
    
    Vector3D    to_screen(const Centimeter3D&v)
    {
        return Vector3D(to_screen(v.x), to_screen(v.y), to_screen(v.z));
    }
    
    Vector4D    to_screen(const Centimeter4D&v)
    {
        return Vector4D(to_screen(v.x), to_screen(v.y), to_screen(v.z), to_screen(v.w));
    }
    

    Vector1D    to_screen(const Foot1D&v)
    {
        return Vector1D(to_screen(v.x));
    }
    
    Vector2D    to_screen(const Foot2D&v)
    {
        return Vector2D(to_screen(v.x), to_screen(v.y));
    }
    
    Vector3D    to_screen(const Foot3D&v)
    {
        return Vector3D(to_screen(v.x), to_screen(v.y), to_screen(v.z));
    }
    
    Vector4D    to_screen(const Foot4D&v)
    {
        return Vector4D(to_screen(v.x), to_screen(v.y), to_screen(v.z), to_screen(v.w));
    }
    
    Vector1D    to_screen(const Inch1D&v)
    {
        return Vector1D(to_screen(v.x));
    }
    
    Vector2D    to_screen(const Inch2D&v)
    {
        return Vector2D(to_screen(v.x), to_screen(v.y));
    }
    
    Vector3D    to_screen(const Inch3D&v)
    {
        return Vector3D(to_screen(v.x), to_screen(v.y), to_screen(v.z));
    }
    
    Vector4D    to_screen(const Inch4D&v)
    {
        return Vector4D(to_screen(v.x), to_screen(v.y), to_screen(v.z), to_screen(v.w));
    }
    

    Vector1D    to_screen(const Kilometer1D&v)
    {
        return Vector1D(to_screen(v.x));
    }
    
    Vector2D    to_screen(const Kilometer2D&v)
    {
        return Vector2D(to_screen(v.x), to_screen(v.y));
    }
    
    Vector3D    to_screen(const Kilometer3D&v)
    {
        return Vector3D(to_screen(v.x), to_screen(v.y), to_screen(v.z));
    }
    
    Vector4D    to_screen(const Kilometer4D&v)
    {
        return Vector4D(to_screen(v.x), to_screen(v.y), to_screen(v.z), to_screen(v.w));
    }
    

    Vector1D    to_screen(const Meter1D&v)
    {
        return Vector1D(to_screen(v.x));
    }
    
    Vector2D    to_screen(const Meter2D&v)
    {
        return Vector2D(to_screen(v.x), to_screen(v.y));
    }
    
    Vector3D    to_screen(const Meter3D&v)
    {
        return Vector3D(to_screen(v.x), to_screen(v.y), to_screen(v.z));
    }
    
    Vector4D    to_screen(const Meter4D&v)
    {
        return Vector4D(to_screen(v.x), to_screen(v.y), to_screen(v.z), to_screen(v.w));
    }
    
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    Centimeter  to_centimeter(double v)
    {
        switch(gLengthUnit){
        case LengthUnit::Centimeter:
            return Centimeter(v);
        case LengthUnit::Foot:
            return Foot(v);
        case LengthUnit::Inch:
            return Inch(v);
        case LengthUnit::Kilometer:
            return Kilometer(v);
        case LengthUnit::Meter:
            return Meter(v);
        default:
            return {v};
        }
    }

    Centimeter1D    to_centimeter(const Vector1D&v)
    {
        return Centimeter1D(to_centimeter(v.x));
    }
    
    Centimeter2D    to_centimeter(const Vector2D&v)
    {
        return Centimeter2D(to_centimeter(v.x), to_centimeter(v.y));
    }
    
    Centimeter3D    to_centimeter(const Vector3D&v)
    {
        return Centimeter3D(to_centimeter(v.x), to_centimeter(v.y), to_centimeter(v.z));
    }
    
    Centimeter4D    to_centimeter(const Vector4D&v)
    {
        return Centimeter4D(to_centimeter(v.x), to_centimeter(v.y), to_centimeter(v.z), to_centimeter(v.w));
    }


    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    Foot   to_foot(double v)
    {
        switch(gLengthUnit){
        case LengthUnit::Centimeter:
            return Centimeter(v);
        case LengthUnit::Foot:
            return Foot(v);
        case LengthUnit::Inch:
            return Inch(v);
        case LengthUnit::Kilometer:
            return Kilometer(v);
        case LengthUnit::Meter:
            return Meter(v);
        default:
            return {v};
        }
    }

    Foot1D    to_foot(const Vector1D&v)
    {
        return Foot1D(to_foot(v.x));
    }
    
    Foot2D    to_foot(const Vector2D&v)
    {
        return Foot2D(to_foot(v.x), to_foot(v.y));
    }
    
    Foot3D    to_foot(const Vector3D&v)
    {
        return Foot3D(to_foot(v.x), to_foot(v.y), to_foot(v.z));
    }
    
    Foot4D    to_foot(const Vector4D&v)
    {
        return Foot4D(to_foot(v.x), to_foot(v.y), to_foot(v.z), to_foot(v.w));
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    Kilometer   to_kilometer(double v)
    {
        switch(gLengthUnit){
        case LengthUnit::Centimeter:
            return Centimeter(v);
        case LengthUnit::Foot:
            return Foot(v);
        case LengthUnit::Inch:
            return Inch(v);
        case LengthUnit::Kilometer:
            return Kilometer(v);
        case LengthUnit::Meter:
            return Meter(v);
        default:
            return {v};
        }
    }

    Kilometer1D    to_kilometer(const Vector1D&v)
    {
        return Kilometer1D(to_kilometer(v.x));
    }
    
    Kilometer2D    to_kilometer(const Vector2D&v)
    {
        return Kilometer2D(to_kilometer(v.x), to_kilometer(v.y));
    }
    
    Kilometer3D    to_kilometer(const Vector3D&v)
    {
        return Kilometer3D(to_kilometer(v.x), to_kilometer(v.y), to_kilometer(v.z));
    }
    
    Kilometer4D    to_kilometer(const Vector4D&v)
    {
        return Kilometer4D(to_kilometer(v.x), to_kilometer(v.y), to_kilometer(v.z), to_kilometer(v.w));
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    Inch   to_inch(double v)
    {
        switch(gLengthUnit){
        case LengthUnit::Centimeter:
            return Centimeter(v);
        case LengthUnit::Foot:
            return Foot(v);
        case LengthUnit::Inch:
            return Inch(v);
        case LengthUnit::Kilometer:
            return Kilometer(v);
        case LengthUnit::Meter:
            return Meter(v);
        default:
            return {v};
        }
    }

    Inch1D    to_inch(const Vector1D&v)
    {
        return Inch1D(to_inch(v.x));
    }
    
    Inch2D    to_inch(const Vector2D&v)
    {
        return Inch2D(to_inch(v.x), to_inch(v.y));
    }
    
    Inch3D    to_inch(const Vector3D&v)
    {
        return Inch3D(to_inch(v.x), to_inch(v.y), to_inch(v.z));
    }
    
    Inch4D    to_inch(const Vector4D&v)
    {
        return Inch4D(to_inch(v.x), to_inch(v.y), to_inch(v.z), to_inch(v.w));
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    Meter   to_meter(double v)
    {
        switch(gLengthUnit){
        case LengthUnit::Centimeter:
            return Centimeter(v);
        case LengthUnit::Foot:
            return Foot(v);
        case LengthUnit::Inch:
            return Inch(v);
        case LengthUnit::Kilometer:
            return Kilometer(v);
        case LengthUnit::Meter:
            return Meter(v);
        default:
            return {v};
        }
    }

    Meter1D    to_meter(const Vector1D&v)
    {
        return Meter1D(to_meter(v.x));
    }
    
    Meter2D    to_meter(const Vector2D&v)
    {
        return Meter2D(to_meter(v.x), to_meter(v.y));
    }
    
    Meter3D    to_meter(const Vector3D&v)
    {
        return Meter3D(to_meter(v.x), to_meter(v.y), to_meter(v.z));
    }
    
    Meter4D    to_meter(const Vector4D&v)
    {
        return Meter4D(to_meter(v.x), to_meter(v.y), to_meter(v.z), to_meter(v.w));
    }

}
