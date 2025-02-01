////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/TypedID.hpp>
#include <yt/msg/Post.hpp>
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
        
        struct Param {}; //< DEPRECATED
        
    protected:
    
        Command(const Param& p={}); //< DEPRECATED
        
        Command(const Header&);
        Command(const Command&, const Header&);
        virtual ~Command();
        
    private:
        Command(const Command&) = delete;
        Command(Command&&) = delete;
        Command& operator=(const Command&) = delete;
        Command& operator=(Command&&) = delete;
        
    };
}
