////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PNearPlane.hpp"
#include <yq/tachyon/command/camera/SetNearPlaneCommand.hpp>

namespace yq::tachyon {
    PNearPlane::PNearPlane(const INearPlane& i) : m_near_plane(i.near_plane())
    {
        if(i.near_plane(DISABLED))
            m_flags |= F::Disabled;
        if(i.near_plane(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PNearPlane::~PNearPlane()
    {
    }

    double  PNearPlane::near_plane() const
    {
        return m_near_plane;
    }

    bool    PNearPlane::near_plane(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool    PNearPlane::near_plane(settable_k) const 
    {
        return m_flags(F::Settable);
    }
        
    void    PNearPlane::near_plane(set_k, double v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetNearPlaneCommand({.target=object()}, v));
        }
    }
}
