////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LightIntensityEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LightIntensityEvent)

namespace yq::tachyon {

    LightIntensityEvent::LightIntensityEvent(const Header&h, float v) : LightEvent(h), m_intensity(v)
    {
    }

    LightIntensityEvent::LightIntensityEvent(const LightIntensityEvent& cp, const Header& h) : LightEvent(cp, h), m_intensity(cp.m_intensity)
    {
    }
    
    LightIntensityEvent::~LightIntensityEvent()
    {
    }

    PostCPtr    LightIntensityEvent::clone(rebind_k, const Header&h) const 
    {
        return new LightIntensityEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void LightIntensityEvent::init_meta()
    {
        auto w = writer<LightIntensityEvent>();
        w.description("Light Intensity Event");
        w.property("intensity", &LightIntensityEvent::m_intensity);
    }
}
