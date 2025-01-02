////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/Post.hpp>
#include <yt/typedef/command.hpp>

namespace yq::tachyon {
    class CommandInfo : public PostInfo {
    public:
        template <typename C> class Writer;

        CommandInfo(std::string_view zName, PostInfo& base, const std::source_location& sl=std::source_location::current());
    };

    class Command : public Post {
        YQ_OBJECT_INFO(CommandInfo)
        YQ_OBJECT_DECLARE(Command, Post)
        template <class> friend class Ref;
    public:
   
        static void init_info();
        
    protected:
        Command(const Param&);
        virtual ~Command();
    };
}
