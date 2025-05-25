////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Spatial2.hpp>
#include <tachyon/api/Spatial2Data.hpp>
#include <tachyon/api/SpatialInfoWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class Spatial²Info::Writer : public SpatialInfo::Writer<C> {
    public:
    
        Writer(Spatial²Info* pInfo) : SpatialInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(Spatial²Info& pInfo) : Writer(&pInfo)
        {
        }

    private:
        Spatial²Info* m_meta;
    };
}
