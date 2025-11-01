////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeᶻCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeᶻCommand, SizeCommand)
    public:
        SetMaxSizeᶻCommand(const Header&, double);
    
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeᶻCommand(const Header&);
        SetMaxSizeᶻCommand(const SetMaxSizeᶻCommand&, const Header&);
        ~SetMaxSizeᶻCommand();

    private:
        double   m_z = 0.;
        
        SetMaxSizeᶻCommand(const SetMaxSizeᶻCommand&) = delete;
        SetMaxSizeᶻCommand(SetMaxSizeᶻCommand&&) = delete;
        SetMaxSizeᶻCommand& operator=(const SetMaxSizeᶻCommand&) = delete;
        SetMaxSizeᶻCommand& operator=(SetMaxSizeᶻCommand&&) = delete;
    };
}
