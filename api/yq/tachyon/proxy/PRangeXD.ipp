////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PRangeXD.hpp"
#include <yq/tachyon/command/range/SetRangeXDCommand.hpp>

namespace yq::tachyon {
    PRangeˣD::PRangeˣD(const IRangeˣD& i) : m_xRange(i.x_range())
    {
        if(i.x_range(DISABLED))
            m_flags |= F::Disabled;
        if(i.x_range(SETTABLE))
            m_flags |= F::Settable;
    }

    PRangeˣD::~PRangeˣD()
    {
    }

    bool        PRangeˣD::x_range(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PRangeˣD::x_range(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
        
    void        PRangeˣD::x_range(set_k, const RangeD& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetRangeˣDCommand({.target=object()}, v));
        }
    }
}
