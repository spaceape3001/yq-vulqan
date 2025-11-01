////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PFarPlane.hpp"
#include <yq/tachyon/command/camera/SetFarPlaneCommand.hpp>

namespace yq::tachyon {
    PFarPlane::PFarPlane(const IFarPlane& i) : m_far_plane(i.far_plane())
    {
        if(i.far_plane(DISABLED))
            m_flags |= F::Disabled;
        if(i.far_plane(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PFarPlane::~PFarPlane()
    {
    }

    double  PFarPlane::far_plane() const
    {
        return m_far_plane;
    }

    bool    PFarPlane::far_plane(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool    PFarPlane::far_plane(settable_k) const 
    {
        return m_flags(F::Settable);
    }
        
    void    PFarPlane::far_plane(set_k, double v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetFarPlaneCommand({.target=object()}, v));
        }
    }
}
