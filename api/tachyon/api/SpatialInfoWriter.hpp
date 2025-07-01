////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Spatial.hpp>
#include <tachyon/api/SpatialData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class SpatialInfo::Writer : public TachyonMeta::Writer<C> {
    public:
    
        Writer(SpatialInfo* pInfo) : TachyonMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(SpatialInfo& pInfo) : Writer(&pInfo)
        {
        }

    private:
        SpatialInfo* m_meta;
    };
}
