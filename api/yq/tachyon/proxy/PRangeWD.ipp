////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PRangeWD.hpp"
#include <yq/tachyon/command/range/SetRangeWDCommand.hpp>

namespace yq::tachyon {
    PRangeʷD::PRangeʷD(const IRangeʷD& i) : m_wRange(i.w_range())
    {
        if(i.w_range(DISABLED))
            m_flags |= F::Disabled;
        if(i.w_range(SETTABLE))
            m_flags |= F::Settable;
    }

    PRangeʷD::~PRangeʷD()
    {
    }

    bool        PRangeʷD::w_range(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PRangeʷD::w_range(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
        
    void        PRangeʷD::w_range(set_k, const RangeD& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRangeʷDCommand({.target=object()}, v));
        }
    }
}
