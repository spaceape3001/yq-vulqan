////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/app/Engine.hpp>
#include <yq/tachyon/app/EngineData.hpp>
#include <yq/tachyon/api/ManagerMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of engine information
    */
    template <typename C>
    class EngineMeta::Writer : public ManagerMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(EngineMeta* engineInfo) : ManagerMeta::Writer<C>(engineInfo), m_meta(engineInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(EngineMeta& engineInfo) : Writer(&engineInfo)
        {
        }

    private:
        EngineMeta* m_meta;
    };
}
