////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Controller.hpp>
#include <tachyon/api/ControllerData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of manager information
    */
    template <typename C>
    class ControllerInfo::Writer : public TachyonInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(ControllerInfo* theInfo) : TachyonInfo::Writer<C>(theInfo), m_meta(theInfo)
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
