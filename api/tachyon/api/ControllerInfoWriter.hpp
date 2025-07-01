////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Controller.hpp>
#include <tachyon/api/ControllerData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of manager information
    */
    template <typename C>
    class ControllerInfo::Writer : public TachyonMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(ControllerInfo* theInfo) : TachyonMeta::Writer<C>(theInfo), m_meta(theInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(ControllerInfo& theInfo) : Writer(&theInfo)
        {
        }

    private:
        ControllerInfo* m_meta;
    };
}
