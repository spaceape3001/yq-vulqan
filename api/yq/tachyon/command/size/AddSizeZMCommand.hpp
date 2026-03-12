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
    class AddSizeᶻMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeᶻMCommand, SizeCommand)
    public:
        AddSizeᶻMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeᶻMCommand(const AddSizeᶻMCommand&, const Header&);
        AddSizeᶻMCommand(const Header&);
        ~AddSizeᶻMCommand();

    private:
        Meter  m_Δz = 0.0;
        
        AddSizeᶻMCommand(const AddSizeᶻMCommand&) = delete;
        AddSizeᶻMCommand(AddSizeᶻMCommand&&) = delete;
        AddSizeᶻMCommand& operator=(const AddSizeᶻMCommand&) = delete;
        AddSizeᶻMCommand& operator=(AddSizeᶻMCommand&&) = delete;
    };
}
