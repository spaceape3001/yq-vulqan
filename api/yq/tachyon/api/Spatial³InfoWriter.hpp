////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial³.hpp>
#include <yq/tachyon/api/SpatialInfoWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class Spatial³Info::Writer : public ObjectInfo::Writer<C> {
    public:
    
        Writer(Spatial³Info* pInfo) : ObjectInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(Spatial³Info& pInfo) : Writer(&pInfo)
        {
        }

    private:
        Spatial³Info* m_meta;
    };
}
