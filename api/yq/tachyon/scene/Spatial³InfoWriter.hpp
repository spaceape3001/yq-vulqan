////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/scene/SpatialInfoWriter.hpp>
#include <yq/tachyon/scene3/Spatial³.hpp>
#include <yq/tachyon/scene3/Spatial³Data.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class Spatial³Info::Writer : public SpatialInfo::Writer<C> {
    public:
    
        Writer(Spatial³Info* pInfo) : SpatialInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(Spatial³Info& pInfo) : Writer(&pInfo)
        {
        }

    private:
        Spatial³Info* m_meta;
    };
}
