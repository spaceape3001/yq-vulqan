////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class MeshCommand : public Command {
        YQ_OBJECT_DECLARE(MeshCommand, Command)
    public:
    
        static void init_meta();

    protected:
        MeshCommand(const Header&);
        MeshCommand(const MeshCommand&, const Header&);
        ~MeshCommand();
        
    private:
        MeshCommand(const MeshCommand&) = delete;
        MeshCommand(MeshCommand&&) = delete;
        MeshCommand& operator=(const MeshCommand&) = delete;
        MeshCommand& operator=(MeshCommand&&) = delete;
    };
}
