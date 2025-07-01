////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeᶻCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeᶻCommand, SizeCommand)
    public:
        SetMinSizeᶻCommand(const Header&, double);
    
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeᶻCommand(const Header&);
        SetMinSizeᶻCommand(const SetMinSizeᶻCommand&, const Header&);
        ~SetMinSizeᶻCommand();

    private:
        double   m_z = 0.;
        
        SetMinSizeᶻCommand(const SetMinSizeᶻCommand&) = delete;
        SetMinSizeᶻCommand(SetMinSizeᶻCommand&&) = delete;
        SetMinSizeᶻCommand& operator=(const SetMinSizeᶻCommand&) = delete;
        SetMinSizeᶻCommand& operator=(SetMinSizeᶻCommand&&) = delete;
    };
}
