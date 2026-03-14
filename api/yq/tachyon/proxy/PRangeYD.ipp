////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PRangeYD.hpp"
#include <yq/tachyon/command/range/SetRangeYDCommand.hpp>

namespace yq::tachyon {
    PRangeʸD::PRangeʸD(const IRangeʸD& i) : m_yRange(i.y_range())
    {
        if(i.y_range(DISABLED))
            m_flags |= F::Disabled;
        if(i.y_range(SETTABLE))
            m_flags |= F::Settable;
    }

    PRangeʸD::~PRangeʸD()
    {
    }

    bool        PRangeʸD::y_range(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PRangeʸD::y_range(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
        
    void        PRangeʸD::y_range(set_k, const RangeD& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRangeʸDCommand({.target=object()}, v));
        }
    }
}
