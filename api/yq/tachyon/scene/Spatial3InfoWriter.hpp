////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/scene/SpatialInfoWriter.hpp>
#include <yq/tachyon/scene3/Spatial3.hpp>
#include <yq/tachyon/scene3/Spatial3Data.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class Spatial3Info::Writer : public SpatialInfo::Writer<C> {
    public:
    
        Writer(Spatial3Info* pInfo) : SpatialInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(Spatial3Info& pInfo) : Writer(&pInfo)
        {
        }

    private:
        Spatial3Info* m_meta;
    };
}
