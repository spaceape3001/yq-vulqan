////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddSizeᶻCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeᶻCMCommand, SizeCommand)
    public:
        AddSizeᶻCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeᶻCMCommand(const AddSizeᶻCMCommand&, const Header&);
        AddSizeᶻCMCommand(const Header&);
        ~AddSizeᶻCMCommand();

    private:
        Centimeter  m_Δz = 0.0;
        
        AddSizeᶻCMCommand(const AddSizeᶻCMCommand&) = delete;
        AddSizeᶻCMCommand(AddSizeᶻCMCommand&&) = delete;
        AddSizeᶻCMCommand& operator=(const AddSizeᶻCMCommand&) = delete;
        AddSizeᶻCMCommand& operator=(AddSizeᶻCMCommand&&) = delete;
    };
}
