////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PFieldOfView.hpp"
#include <tachyon/command/camera/SetFOVCommand.hpp>

namespace yq::tachyon {
    PFieldOfView::PFieldOfView(const IFieldOfView& i) : m_field_of_view(i.field_of_view())
    {
        if(i.field_of_view(DISABLED))
            m_flags |= F::Disabled;
        if(i.field_of_view(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PFieldOfView::~PFieldOfView()
    {
    }

    unit::Degree  PFieldOfView::field_of_view() const
    {
        return m_field_of_view;
    }

    bool    PFieldOfView::field_of_view(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool    PFieldOfView::field_of_view(settable_k) const 
    {
        return m_flags(F::Settable);
    }
        
    void    PFieldOfView::field_of_view(set_k, unit::Degree v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetFOVCommand({.target=object()}, v));
        }
    }
}
