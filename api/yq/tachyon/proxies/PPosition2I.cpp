////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition2I.hpp"
#include <yq/tachyon/commands/MovePosition2I.hpp>
#include <yq/tachyon/commands/SetPosition2I.hpp>

namespace yq::tachyon {
    PPosition2I::PPosition2I(const IPosition2I& i)
    {
        if(i.position2i(DISABLED))
            m_flags |= F::Disabled;
        if(i.position2i(SETTABLE))
            m_flags |= F::Settable;
        if(i.position2i(MOVEABLE))
            m_flags |= F::Moveable;
    }

    void        PPosition2I::position2i(set_t, const Vector2I& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            dispatch(new SetPosition2I(id(), v));
        }
    }
    
    void        PPosition2I::position2i(move_t, const Vector2I& v) 
    {
        if(m_flags(F::Moveable) && !m_flags(F::Disabled)){
            dispatch(new MovePosition2I(id(), v));
        }
    }
}
