////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial³.hpp>
#include <yq/tachyon/api/Spatial³Data.hpp>
#include <yq/tachyon/api/SpatialInfoWriter.hpp>

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
