////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddMaxSizeᶻCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeᶻCMCommand, SizeCommand)
    public:
        AddMaxSizeᶻCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeᶻCMCommand(const AddMaxSizeᶻCMCommand&, const Header&);
        AddMaxSizeᶻCMCommand(const Header&);
        ~AddMaxSizeᶻCMCommand();

    private:
        Centimeter  m_Δz = 0.0;
        
        AddMaxSizeᶻCMCommand(const AddMaxSizeᶻCMCommand&) = delete;
        AddMaxSizeᶻCMCommand(AddMaxSizeᶻCMCommand&&) = delete;
        AddMaxSizeᶻCMCommand& operator=(const AddMaxSizeᶻCMCommand&) = delete;
        AddMaxSizeᶻCMCommand& operator=(AddMaxSizeᶻCMCommand&&) = delete;
    };
}
