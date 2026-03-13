////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddCountᶻUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCountᶻUCommand, CountCommand)
    public:
        AddCountᶻUCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCountᶻUCommand(const AddCountᶻUCommand&, const Header&);
        AddCountᶻUCommand(const Header&);
        ~AddCountᶻUCommand();

    private:
        unsigned  m_Δz = 0.0;
        
        AddCountᶻUCommand(const AddCountᶻUCommand&) = delete;
        AddCountᶻUCommand(AddCountᶻUCommand&&) = delete;
        AddCountᶻUCommand& operator=(const AddCountᶻUCommand&) = delete;
        AddCountᶻUCommand& operator=(AddCountᶻUCommand&&) = delete;
    };
}
