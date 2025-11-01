////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/SpatialData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class SpatialMeta::Writer : public TachyonMeta::Writer<C> {
    public:
    
        Writer(SpatialMeta* pInfo) : TachyonMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(SpatialMeta& pInfo) : Writer(&pInfo)
        {
        }

    private:
        SpatialMeta* m_meta;
    };
}
