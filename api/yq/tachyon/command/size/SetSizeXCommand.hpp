////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeˣDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeˣDCommand, SizeCommand)
    public:
        SetSizeˣDCommand(const Header&, double);
    
        static void init_meta();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeˣDCommand(const Header&);
        SetSizeˣDCommand(const SetSizeˣDCommand&, const Header&);
        ~SetSizeˣDCommand();

    private:
        double   m_x = 0.;
        
        SetSizeˣDCommand(const SetSizeˣDCommand&) = delete;
        SetSizeˣDCommand(SetSizeˣDCommand&&) = delete;
        SetSizeˣDCommand& operator=(const SetSizeˣDCommand&) = delete;
        SetSizeˣDCommand& operator=(SetSizeˣDCommand&&) = delete;
    };
}
