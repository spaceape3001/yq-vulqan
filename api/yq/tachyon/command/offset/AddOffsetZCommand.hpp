////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/OffsetCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their offset by given amount
    class AddOffsetᶻCommand : public OffsetCommand {
        YQ_OBJECT_DECLARE(AddOffsetᶻCommand, OffsetCommand)
    public:
        AddOffsetᶻCommand(const Header&, double Δz);
    
        static void init_meta();
        
        double  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddOffsetᶻCommand(const AddOffsetᶻCommand&, const Header&);
        AddOffsetᶻCommand(const Header&);
        ~AddOffsetᶻCommand();
        
    private:
        double  m_Δz = 0.0;
        
        AddOffsetᶻCommand(const AddOffsetᶻCommand&) = delete;
        AddOffsetᶻCommand(AddOffsetᶻCommand&&) = delete;
        AddOffsetᶻCommand& operator=(const AddOffsetᶻCommand&) = delete;
        AddOffsetᶻCommand& operator=(AddOffsetᶻCommand&&) = delete;
    };
}
