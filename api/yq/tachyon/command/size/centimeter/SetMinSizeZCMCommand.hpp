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
    class SetMinSizeᶻCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeᶻCMCommand, SizeCommand)
    public:
        SetMinSizeᶻCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeᶻCMCommand(const Header&);
        SetMinSizeᶻCMCommand(const SetMinSizeᶻCMCommand&, const Header&);
        ~SetMinSizeᶻCMCommand();

    private:
        Centimeter   m_z = 0.;
        
        SetMinSizeᶻCMCommand(const SetMinSizeᶻCMCommand&) = delete;
        SetMinSizeᶻCMCommand(SetMinSizeᶻCMCommand&&) = delete;
        SetMinSizeᶻCMCommand& operator=(const SetMinSizeᶻCMCommand&) = delete;
        SetMinSizeᶻCMCommand& operator=(SetMinSizeᶻCMCommand&&) = delete;
    };
}
