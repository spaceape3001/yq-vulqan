////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/OffsetCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-offset
    class SetOffsetᶻCommand : public OffsetCommand {
        YQ_OBJECT_DECLARE(SetOffsetᶻCommand, OffsetCommand)
    public:
        SetOffsetᶻCommand(const Header&, double);
        
        static void init_meta();
        
        double  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetOffsetᶻCommand(const SetOffsetᶻCommand&, const Header&);
        ~SetOffsetᶻCommand();
        
    private:
        double  m_z = 0.0;
        
        SetOffsetᶻCommand(const SetOffsetᶻCommand&) = delete;
        SetOffsetᶻCommand(SetOffsetᶻCommand&&) = delete;
        SetOffsetᶻCommand& operator=(const SetOffsetᶻCommand&) = delete;
        SetOffsetᶻCommand& operator=(SetOffsetᶻCommand&&) = delete;
    };
}
