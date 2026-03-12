////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeᶻDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeᶻDCommand, SizeCommand)
    public:
        SetMaxSizeᶻDCommand(const Header&, double);
    
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeᶻDCommand(const Header&);
        SetMaxSizeᶻDCommand(const SetMaxSizeᶻDCommand&, const Header&);
        ~SetMaxSizeᶻDCommand();

    private:
        double   m_z = 0.;
        
        SetMaxSizeᶻDCommand(const SetMaxSizeᶻDCommand&) = delete;
        SetMaxSizeᶻDCommand(SetMaxSizeᶻDCommand&&) = delete;
        SetMaxSizeᶻDCommand& operator=(const SetMaxSizeᶻDCommand&) = delete;
        SetMaxSizeᶻDCommand& operator=(SetMaxSizeᶻDCommand&&) = delete;
    };
}
