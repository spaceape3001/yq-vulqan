////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeᶻCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeᶻCommand, SizeCommand)
    public:
        SetSizeᶻCommand(const Header&, double);
    
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeᶻCommand(const Header&);
        SetSizeᶻCommand(const SetSizeᶻCommand&, const Header&);
        ~SetSizeᶻCommand();

    private:
        double   m_z = 0.;
        
        SetSizeᶻCommand(const SetSizeᶻCommand&) = delete;
        SetSizeᶻCommand(SetSizeᶻCommand&&) = delete;
        SetSizeᶻCommand& operator=(const SetSizeᶻCommand&) = delete;
        SetSizeᶻCommand& operator=(SetSizeᶻCommand&&) = delete;
    };
}
