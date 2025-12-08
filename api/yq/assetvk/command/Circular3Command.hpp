////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Circular³Command : public SpatialCommand {
        YQ_OBJECT_DECLARE(Circular³Command, SpatialCommand)
    public:
    
        static void init_meta();

    protected:
        Circular³Command(const Header&);
        Circular³Command(const Circular³Command&, const Header&);
        ~Circular³Command();
        
    private:
        Circular³Command(const Circular³Command&) = delete;
        Circular³Command(Circular³Command&&) = delete;
        Circular³Command& operator=(const Circular³Command&) = delete;
        Circular³Command& operator=(Circular³Command&&) = delete;
    };
}
