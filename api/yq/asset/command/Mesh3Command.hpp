////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Mesh³Command : public SpatialCommand {
        YQ_OBJECT_DECLARE(Mesh³Command, SpatialCommand)
    public:
    
        static void init_meta();

    protected:
        Mesh³Command(const Header&);
        Mesh³Command(const Mesh³Command&, const Header&);
        ~Mesh³Command();
        
    private:
        Mesh³Command(const Mesh³Command&) = delete;
        Mesh³Command(Mesh³Command&&) = delete;
        Mesh³Command& operator=(const Mesh³Command&) = delete;
        Mesh³Command& operator=(Mesh³Command&&) = delete;
    };
}
