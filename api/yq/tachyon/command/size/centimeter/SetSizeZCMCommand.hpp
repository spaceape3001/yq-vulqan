////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeᶻCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeᶻCMCommand, SizeCommand)
    public:
        SetSizeᶻCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeᶻCMCommand(const Header&);
        SetSizeᶻCMCommand(const SetSizeᶻCMCommand&, const Header&);
        ~SetSizeᶻCMCommand();

    private:
        Centimeter   m_z = 0.;
        
        SetSizeᶻCMCommand(const SetSizeᶻCMCommand&) = delete;
        SetSizeᶻCMCommand(SetSizeᶻCMCommand&&) = delete;
        SetSizeᶻCMCommand& operator=(const SetSizeᶻCMCommand&) = delete;
        SetSizeᶻCMCommand& operator=(SetSizeᶻCMCommand&&) = delete;
    };
}
