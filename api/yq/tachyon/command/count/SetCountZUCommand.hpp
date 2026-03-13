////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCountᶻUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCountᶻUCommand, CountCommand)
    public:
        SetCountᶻUCommand(const Header&, unsigned);
    
        static void init_meta();
        
        unsigned  z() const { return m_z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCountᶻUCommand(const Header&);
        SetCountᶻUCommand(const SetCountᶻUCommand&, const Header&);
        ~SetCountᶻUCommand();

    private:
        unsigned   m_z = 0.;
        
        SetCountᶻUCommand(const SetCountᶻUCommand&) = delete;
        SetCountᶻUCommand(SetCountᶻUCommand&&) = delete;
        SetCountᶻUCommand& operator=(const SetCountᶻUCommand&) = delete;
        SetCountᶻUCommand& operator=(SetCountᶻUCommand&&) = delete;
    };
}
