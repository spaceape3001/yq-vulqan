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
    class SetMaxSizeᶻCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeᶻCMCommand, SizeCommand)
    public:
        SetMaxSizeᶻCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeᶻCMCommand(const Header&);
        SetMaxSizeᶻCMCommand(const SetMaxSizeᶻCMCommand&, const Header&);
        ~SetMaxSizeᶻCMCommand();

    private:
        Centimeter   m_z = 0.;
        
        SetMaxSizeᶻCMCommand(const SetMaxSizeᶻCMCommand&) = delete;
        SetMaxSizeᶻCMCommand(SetMaxSizeᶻCMCommand&&) = delete;
        SetMaxSizeᶻCMCommand& operator=(const SetMaxSizeᶻCMCommand&) = delete;
        SetMaxSizeᶻCMCommand& operator=(SetMaxSizeᶻCMCommand&&) = delete;
    };
}
