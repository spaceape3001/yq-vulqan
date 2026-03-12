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
    class SetSizeᶻMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeᶻMCommand, SizeCommand)
    public:
        SetSizeᶻMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeᶻMCommand(const Header&);
        SetSizeᶻMCommand(const SetSizeᶻMCommand&, const Header&);
        ~SetSizeᶻMCommand();

    private:
        Meter   m_z = 0.;
        
        SetSizeᶻMCommand(const SetSizeᶻMCommand&) = delete;
        SetSizeᶻMCommand(SetSizeᶻMCommand&&) = delete;
        SetSizeᶻMCommand& operator=(const SetSizeᶻMCommand&) = delete;
        SetSizeᶻMCommand& operator=(SetSizeᶻMCommand&&) = delete;
    };
}
