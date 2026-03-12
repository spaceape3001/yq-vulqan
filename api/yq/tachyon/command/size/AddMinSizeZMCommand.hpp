////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddMinSizeᶻMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeᶻMCommand, SizeCommand)
    public:
        AddMinSizeᶻMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeᶻMCommand(const AddMinSizeᶻMCommand&, const Header&);
        AddMinSizeᶻMCommand(const Header&);
        ~AddMinSizeᶻMCommand();

    private:
        Meter  m_Δz = 0.0;
        
        AddMinSizeᶻMCommand(const AddMinSizeᶻMCommand&) = delete;
        AddMinSizeᶻMCommand(AddMinSizeᶻMCommand&&) = delete;
        AddMinSizeᶻMCommand& operator=(const AddMinSizeᶻMCommand&) = delete;
        AddMinSizeᶻMCommand& operator=(AddMinSizeᶻMCommand&&) = delete;
    };
}
