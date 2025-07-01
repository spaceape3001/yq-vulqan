////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Command.hpp>
#include <tachyon/api/PostMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of event information
    */
    template <typename C>
    class CommandInfo::Writer : public PostMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(CommandInfo* cmdInfo) : PostMeta::Writer<C>(cmdInfo), m_meta(cmdInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(CommandInfo& cmdInfo) : Writer(&cmdInfo)
        {
        }

    private:
        CommandInfo* m_meta;
    };
}
