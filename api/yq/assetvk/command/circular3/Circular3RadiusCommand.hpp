////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/command/Circular3Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Circular³RadiusCommand : public Circular³Command {
        YQ_OBJECT_DECLARE(Circular³RadiusCommand, Circular³Command)
    public:
    
        static void init_meta();
        Circular³RadiusCommand(const Header&, double);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        double    radius() const { return m_radius; }
        
    protected:
        Circular³RadiusCommand(const Circular³RadiusCommand&, const Header&);
        ~Circular³RadiusCommand();
        
    private:
        double    m_radius;
    
        Circular³RadiusCommand(const Circular³RadiusCommand&) = delete;
        Circular³RadiusCommand(Circular³RadiusCommand&&) = delete;
        Circular³RadiusCommand& operator=(const Circular³RadiusCommand&) = delete;
        Circular³RadiusCommand& operator=(Circular³RadiusCommand&&) = delete;
    };
}
