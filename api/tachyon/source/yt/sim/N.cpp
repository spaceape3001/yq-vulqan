////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/sim/N.hpp>
#include <yt/sim/NData.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {

    ИSnap::~ИSnap()
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ИData::~ИData()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    И::И()
    {
    }
    
    И::~И()
    {
    }

    void    И::finalize(ИData&) const
    {
        // nothing to do (AT THE MOMENT)
    }

    void    И::mark()
    {
        Tachyon*t   = dynamic_cast<Tachyon*>(this);
        if(t)
            t->mark();
    }

    void    И::snap(ИSnap& sn) const
    {
        sn.spatial  = m_spatial;
    }
}
