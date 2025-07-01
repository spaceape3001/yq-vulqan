////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Spatial3.hpp>
#include <tachyon/api/Spatial3Data.hpp>
#include <tachyon/api/SpatialMetaWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class Spatial³Info::Writer : public SpatialMeta::Writer<C> {
    public:
    
        Writer(Spatial³Info* pInfo) : SpatialMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(Spatial³Info& pInfo) : Writer(&pInfo)
        {
        }

    private:
        Spatial³Info* m_meta;
    };
}
