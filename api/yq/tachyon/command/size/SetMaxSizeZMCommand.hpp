////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/MKS.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeᶻMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeᶻMCommand, SizeCommand)
    public:
        SetMaxSizeᶻMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeᶻMCommand(const Header&);
        SetMaxSizeᶻMCommand(const SetMaxSizeᶻMCommand&, const Header&);
        ~SetMaxSizeᶻMCommand();

    private:
        Meter   m_z = 0.;
        
        SetMaxSizeᶻMCommand(const SetMaxSizeᶻMCommand&) = delete;
        SetMaxSizeᶻMCommand(SetMaxSizeᶻMCommand&&) = delete;
        SetMaxSizeᶻMCommand& operator=(const SetMaxSizeᶻMCommand&) = delete;
        SetMaxSizeᶻMCommand& operator=(SetMaxSizeᶻMCommand&&) = delete;
    };
}
