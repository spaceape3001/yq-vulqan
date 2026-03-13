////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCountᶻCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCountᶻCommand, CountCommand)
    public:
        SetCountᶻCommand(const Header&, unsigned);
    
        static void init_meta();
        
        unsigned  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCountᶻCommand(const Header&);
        SetCountᶻCommand(const SetCountᶻCommand&, const Header&);
        ~SetCountᶻCommand();

    private:
        unsigned   m_z = 0.;
        
        SetCountᶻCommand(const SetCountᶻCommand&) = delete;
        SetCountᶻCommand(SetCountᶻCommand&&) = delete;
        SetCountᶻCommand& operator=(const SetCountᶻCommand&) = delete;
        SetCountᶻCommand& operator=(SetCountᶻCommand&&) = delete;
    };
}
