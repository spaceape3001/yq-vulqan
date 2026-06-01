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
    class AddMinSizeᶻCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeᶻCMCommand, SizeCommand)
    public:
        AddMinSizeᶻCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeᶻCMCommand(const AddMinSizeᶻCMCommand&, const Header&);
        AddMinSizeᶻCMCommand(const Header&);
        ~AddMinSizeᶻCMCommand();

    private:
        Centimeter  m_Δz = 0.0;
        
        AddMinSizeᶻCMCommand(const AddMinSizeᶻCMCommand&) = delete;
        AddMinSizeᶻCMCommand(AddMinSizeᶻCMCommand&&) = delete;
        AddMinSizeᶻCMCommand& operator=(const AddMinSizeᶻCMCommand&) = delete;
        AddMinSizeᶻCMCommand& operator=(AddMinSizeᶻCMCommand&&) = delete;
    };
}
