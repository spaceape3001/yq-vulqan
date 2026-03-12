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
    class AddMaxSizeᶻMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeᶻMCommand, SizeCommand)
    public:
        AddMaxSizeᶻMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeᶻMCommand(const AddMaxSizeᶻMCommand&, const Header&);
        AddMaxSizeᶻMCommand(const Header&);
        ~AddMaxSizeᶻMCommand();

    private:
        Meter  m_Δz = 0.0;
        
        AddMaxSizeᶻMCommand(const AddMaxSizeᶻMCommand&) = delete;
        AddMaxSizeᶻMCommand(AddMaxSizeᶻMCommand&&) = delete;
        AddMaxSizeᶻMCommand& operator=(const AddMaxSizeᶻMCommand&) = delete;
        AddMaxSizeᶻMCommand& operator=(AddMaxSizeᶻMCommand&&) = delete;
    };
}
