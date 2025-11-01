////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial2.hpp>
#include <yq/tachyon/api/Spatial2Data.hpp>
#include <yq/tachyon/api/SpatialMetaWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class Spatial²Meta::Writer : public SpatialMeta::Writer<C> {
    public:
    
        Writer(Spatial²Meta* pInfo) : SpatialMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(Spatial²Meta& pInfo) : Writer(&pInfo)
        {
        }

    private:
        Spatial²Meta* m_meta;
    };
}
