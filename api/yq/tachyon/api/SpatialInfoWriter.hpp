////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class SpatialInfo::Writer : public ObjectInfo::Writer<C> {
    public:
    
        Writer(SpatialInfo* pInfo) : ObjectInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(SpatialInfo& pInfo) : Writer(&pInfo)
        {
        }

    private:
        SpatialInfo* m_meta;
    };
}
