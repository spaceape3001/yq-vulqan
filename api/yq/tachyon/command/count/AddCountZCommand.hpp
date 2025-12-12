////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddCountᶻCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCountᶻCommand, CountCommand)
    public:
        AddCountᶻCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCountᶻCommand(const AddCountᶻCommand&, const Header&);
        AddCountᶻCommand(const Header&);
        ~AddCountᶻCommand();

    private:
        unsigned  m_Δz = 0.0;
        
        AddCountᶻCommand(const AddCountᶻCommand&) = delete;
        AddCountᶻCommand(AddCountᶻCommand&&) = delete;
        AddCountᶻCommand& operator=(const AddCountᶻCommand&) = delete;
        AddCountᶻCommand& operator=(AddCountᶻCommand&&) = delete;
    };
}
