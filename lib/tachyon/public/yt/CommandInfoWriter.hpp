////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/Command.hpp>
#include <yt/PostInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of event information
    */
    template <typename C>
    class CommandInfo::Writer : public PostInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(CommandInfo* cmdInfo) : PostInfo::Writer<C>(cmdInfo), m_meta(cmdInfo)
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
