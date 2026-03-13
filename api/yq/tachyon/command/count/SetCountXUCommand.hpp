////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCountˣUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCountˣUCommand, CountCommand)
    public:
        SetCountˣUCommand(const Header&, unsigned);
    
        static void init_meta();
        
        unsigned  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCountˣUCommand(const Header&);
        SetCountˣUCommand(const SetCountˣUCommand&, const Header&);
        ~SetCountˣUCommand();

    private:
        unsigned   m_x = 0.;
        
        SetCountˣUCommand(const SetCountˣUCommand&) = delete;
        SetCountˣUCommand(SetCountˣUCommand&&) = delete;
        SetCountˣUCommand& operator=(const SetCountˣUCommand&) = delete;
        SetCountˣUCommand& operator=(SetCountˣUCommand&&) = delete;
    };
}
