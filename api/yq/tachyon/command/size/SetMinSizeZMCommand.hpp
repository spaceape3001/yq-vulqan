////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeᶻMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeᶻMCommand, SizeCommand)
    public:
        SetMinSizeᶻMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeᶻMCommand(const Header&);
        SetMinSizeᶻMCommand(const SetMinSizeᶻMCommand&, const Header&);
        ~SetMinSizeᶻMCommand();

    private:
        Meter   m_z = 0.;
        
        SetMinSizeᶻMCommand(const SetMinSizeᶻMCommand&) = delete;
        SetMinSizeᶻMCommand(SetMinSizeᶻMCommand&&) = delete;
        SetMinSizeᶻMCommand& operator=(const SetMinSizeᶻMCommand&) = delete;
        SetMinSizeᶻMCommand& operator=(SetMinSizeᶻMCommand&&) = delete;
    };
}
