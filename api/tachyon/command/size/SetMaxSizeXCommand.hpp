////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeˣCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeˣCommand, SizeCommand)
    public:
        SetMaxSizeˣCommand(const Header&, double);
    
        static void init_info();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeˣCommand(const Header&);
        SetMaxSizeˣCommand(const SetMaxSizeˣCommand&, const Header&);
        ~SetMaxSizeˣCommand();

    private:
        double   m_x = 0.;
        
        SetMaxSizeˣCommand(const SetMaxSizeˣCommand&) = delete;
        SetMaxSizeˣCommand(SetMaxSizeˣCommand&&) = delete;
        SetMaxSizeˣCommand& operator=(const SetMaxSizeˣCommand&) = delete;
        SetMaxSizeˣCommand& operator=(SetMaxSizeˣCommand&&) = delete;
    };
}
