////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeᶻDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeᶻDCommand, SizeCommand)
    public:
        SetSizeᶻDCommand(const Header&, double);
    
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeᶻDCommand(const Header&);
        SetSizeᶻDCommand(const SetSizeᶻDCommand&, const Header&);
        ~SetSizeᶻDCommand();

    private:
        double   m_z = 0.;
        
        SetSizeᶻDCommand(const SetSizeᶻDCommand&) = delete;
        SetSizeᶻDCommand(SetSizeᶻDCommand&&) = delete;
        SetSizeᶻDCommand& operator=(const SetSizeᶻDCommand&) = delete;
        SetSizeᶻDCommand& operator=(SetSizeᶻDCommand&&) = delete;
    };
}
