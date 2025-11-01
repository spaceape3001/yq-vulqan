////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Manager.hpp>
#include <tachyon/api/ManagerData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of manager information
    */
    template <typename C>
    class ManagerMeta::Writer : public TachyonMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(ManagerMeta* managerInfo) : TachyonMeta::Writer<C>(managerInfo), m_meta(managerInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(ManagerMeta& managerInfo) : Writer(&managerInfo)
        {
        }

    private:
        ManagerMeta* m_meta;
    };
}
