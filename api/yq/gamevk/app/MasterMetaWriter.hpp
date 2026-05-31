////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/gamevk/app/Master.hpp>
#include <yq/gamevk/app/MasterData.hpp>
#include <yq/tachyon/api/ManagerMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of master information
    */
    template <typename C>
    class MasterMeta::Writer : public ManagerMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(MasterMeta* masterInfo) : ManagerMeta::Writer<C>(masterInfo), m_meta(masterInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(MasterMeta& masterInfo) : Writer(&masterInfo)
        {
        }

    private:
        MasterMeta* m_meta;
    };
}
