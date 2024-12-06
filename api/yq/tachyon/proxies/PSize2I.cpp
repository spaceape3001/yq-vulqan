////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PSize2I.hpp"
#include <yq/tachyon/commands/MoveSize2I.hpp>
#include <yq/tachyon/commands/SetSize2I.hpp>

namespace yq::tachyon {
    PSize2I::PSize2I(const ISize2I& i)
    {
        if(i.size2i(DISABLED))
            m_flags |= F::Disabled;
        if(i.size2i(SETTABLE))
            m_flags |= F::Settable;
        if(i.size2i(ADJUSTABLE))
            m_flags |= F::Adjustable;
    }

    bool        PSize2I::size2i(disabled_t) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PSize2I::size2i(settable_t) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PSize2I::size2i(adjustable_t) const 
    {
        return m_flags(F::Adjustable);
    }
        
    void        PSize2I::size2i(set_t, const Size2I& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetSize2I(id(), v));
        }
    }
    
    void        PSize2I::size2i(adjust_t, const Size2I& v) 
    {
        if(m_flags(F::Adjustable) && !m_flags(F::Disabled)){
            dispatch(new MoveSize2I(id(), v));
        }
    }
}
