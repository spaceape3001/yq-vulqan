////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeᶻDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeᶻDCommand, SizeCommand)
    public:
        SetMinSizeᶻDCommand(const Header&, double);
    
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeᶻDCommand(const Header&);
        SetMinSizeᶻDCommand(const SetMinSizeᶻDCommand&, const Header&);
        ~SetMinSizeᶻDCommand();

    private:
        double   m_z = 0.;
        
        SetMinSizeᶻDCommand(const SetMinSizeᶻDCommand&) = delete;
        SetMinSizeᶻDCommand(SetMinSizeᶻDCommand&&) = delete;
        SetMinSizeᶻDCommand& operator=(const SetMinSizeᶻDCommand&) = delete;
        SetMinSizeᶻDCommand& operator=(SetMinSizeᶻDCommand&&) = delete;
    };
}
