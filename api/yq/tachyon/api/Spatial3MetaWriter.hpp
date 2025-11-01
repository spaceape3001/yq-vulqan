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
    class Spatial³Meta::Writer : public SpatialMeta::Writer<C> {
    public:
    
        Writer(Spatial³Meta* pInfo) : SpatialMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(Spatial³Meta& pInfo) : Writer(&pInfo)
        {
        }

    private:
        Spatial³Meta* m_meta;
    };
}
