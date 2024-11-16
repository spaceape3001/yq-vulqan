////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaObjectInfoWriter.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    /*! \brief Writer of manager information
    */
    template <typename C>
    class TachyonInfo::Writer : public MetaObjectInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(TachyonInfo* theInfo) : MetaObjectInfo::Writer<C>(theInfo), m_meta(theInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(TachyonInfo& theInfo) : Writer(&theInfo)
        {
        }

    private:
        TachyonInfo* m_meta;
    };
}
