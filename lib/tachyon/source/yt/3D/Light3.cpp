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

YQ_TACHYON_IMPLEMENT(yq::tachyon::Light³)

namespace yq::tachyon {
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
            SimpleSpatial³::Param p3;
            p3.position     = p.position;
            p3.orientation  = p.orientation;
            p3.scale        = p.scale;
            m_spatial       = create<SimpleSpatial³>(CHILD, p3) -> id();
            subscribe(m_spatial, MG::Spatial);
        }
    }
    
    Light³::~Light³()
    {
    }
    
    void Light³::snap(Light³Snap& sn) const
    {
        Light::snap(sn);
    }
    
    void Light³::init_info()
    {
        auto w = writer<Light³>();
        w.description("Light in 3D");
    }
}
