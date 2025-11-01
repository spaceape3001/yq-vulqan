////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeˣCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeˣCommand, SizeCommand)
    public:
        SetSizeˣCommand(const Header&, double);
    
        static void init_meta();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeˣCommand(const Header&);
        SetSizeˣCommand(const SetSizeˣCommand&, const Header&);
        ~SetSizeˣCommand();

    private:
        double   m_x = 0.;
        
        SetSizeˣCommand(const SetSizeˣCommand&) = delete;
        SetSizeˣCommand(SetSizeˣCommand&&) = delete;
        SetSizeˣCommand& operator=(const SetSizeˣCommand&) = delete;
        SetSizeˣCommand& operator=(SetSizeˣCommand&&) = delete;
    };
}
