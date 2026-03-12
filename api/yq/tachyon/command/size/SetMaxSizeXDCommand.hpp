////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeˣDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeˣDCommand, SizeCommand)
    public:
        SetMaxSizeˣDCommand(const Header&, double);
    
        static void init_meta();
        
        double  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeˣDCommand(const Header&);
        SetMaxSizeˣDCommand(const SetMaxSizeˣDCommand&, const Header&);
        ~SetMaxSizeˣDCommand();

    private:
        double   m_x = 0.;
        
        SetMaxSizeˣDCommand(const SetMaxSizeˣDCommand&) = delete;
        SetMaxSizeˣDCommand(SetMaxSizeˣDCommand&&) = delete;
        SetMaxSizeˣDCommand& operator=(const SetMaxSizeˣDCommand&) = delete;
        SetMaxSizeˣDCommand& operator=(SetMaxSizeˣDCommand&&) = delete;
    };
}
