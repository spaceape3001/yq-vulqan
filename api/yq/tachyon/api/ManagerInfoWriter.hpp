////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/api/ManagerData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of manager information
    */
    template <typename C>
    class ManagerInfo::Writer : public TachyonInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(ManagerInfo* managerInfo) : TachyonInfo::Writer<C>(managerInfo), m_meta(managerInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(ManagerInfo& managerInfo) : Writer(&managerInfo)
        {
        }

    private:
        ManagerInfo* m_meta;
    };
}
