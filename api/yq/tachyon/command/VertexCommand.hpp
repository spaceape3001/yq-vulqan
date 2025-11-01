////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class VertexCommand : public Command {
        YQ_OBJECT_DECLARE(VertexCommand, Command)
    public:
    
        static void init_meta();

    protected:
        VertexCommand(const Header&);
        VertexCommand(const VertexCommand&, const Header&);
        ~VertexCommand();
        
    private:
        VertexCommand(const VertexCommand&) = delete;
        VertexCommand(VertexCommand&&) = delete;
        VertexCommand& operator=(const VertexCommand&) = delete;
        VertexCommand& operator=(VertexCommand&&) = delete;
    };
}
