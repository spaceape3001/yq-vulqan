////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCountˣCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCountˣCommand, CountCommand)
    public:
        SetCountˣCommand(const Header&, unsigned);
    
        static void init_meta();
        
        unsigned  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCountˣCommand(const Header&);
        SetCountˣCommand(const SetCountˣCommand&, const Header&);
        ~SetCountˣCommand();

    private:
        unsigned   m_x = 0.;
        
        SetCountˣCommand(const SetCountˣCommand&) = delete;
        SetCountˣCommand(SetCountˣCommand&&) = delete;
        SetCountˣCommand& operator=(const SetCountˣCommand&) = delete;
        SetCountˣCommand& operator=(SetCountˣCommand&&) = delete;
    };
}
