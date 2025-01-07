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

    void    И::set_spatial(TypedID sid)
    {
        if(sid(Type::Spatial)){
            m_spatial   = sid;
            mark();
        }
    }

    void    И::snap(ИSnap& sn) const
    {
        sn.spatial  = (SpatialID) m_spatial.id;
    }

    TachyonID   И::tachyon_id() const
    {
        const Tachyon* t    = dynamic_cast<const Tachyon*>(this);
        if(t)
            return t->id();
        return {};
    }
}
