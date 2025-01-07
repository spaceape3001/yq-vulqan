////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/3D/Light3.hpp>
#include <yt/3D/Light3Bind.hpp>
#include <yt/3D/Light3Data.hpp>
#include <yt/3D/Light3InfoWriter.hpp>
#include <ya/spatials/SimpleSpatial3.hpp>
#include <yt/3D/3DWriter.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Light³)

namespace yq::tachyon {
    Light³Bind::Light³Bind(const Light³* v) : m_light³(v ? v->id() : Light³ID() ) 
    {
    }
    
    Light³Bind::Light³Bind(TypedID v) : m_light³(v(Type::Light³) ? Light³ID(v.id) : Light³ID())
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    Light³Info::Light³Info(std::string_view name, LightInfo& base, const std::source_location& sl) :
        LightInfo(name, base, sl)
    {
    }

    Light³Info::~Light³Info()
    {
    }
    

    Light³::Light³(const Param& p) : Light(p)
    {
        if(!(is_nan(p.position) && is_nan(p.orientation) && is_nan(p.scale))){
            make_simple_spatial(p.position, p.orientation, p.scale);
        }
    }
    
    Light³::~Light³()
    {
    }
    
    void Light³::finalize(Light³Data&d) const
    {
        ③::finalize(d);
        Light::finalize(d);
    }

    void Light³::snap(Light³Snap& sn) const
    {
        ③::snap(sn);
        Light::snap(sn);
    }
    
    void Light³::init_info()
    {
        auto w = writer<Light³>();
        ③::init_info(w);
        w.description("Light in 3D");
    }
}
