////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/TypedID.hpp>
#include <tachyon/api/Post.hpp>
#include <tachyon/typedef/command.hpp>

namespace yq::tachyon {

    /*
        Might have a softer "directive" version, more for grander requests... like 
        a "go to" X directive (ie...an order)
    */

    class CommandMeta : public PostMeta {
    public:
        template <typename C> class Writer;

        CommandMeta(std::string_view zName, PostMeta& base, const std::source_location& sl=std::source_location::current());
    };

    class Command : public Post {
        YQ_OBJECT_INFO(CommandMeta)
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
