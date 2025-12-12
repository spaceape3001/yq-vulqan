////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCountʷCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCountʷCommand, CountCommand)
    public:
        SetCountʷCommand(const Header&, unsigned);
    
        static void init_meta();
        
        unsigned  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCountʷCommand(const Header&);
        SetCountʷCommand(const SetCountʷCommand&, const Header&);
        ~SetCountʷCommand();

    private:
        unsigned   m_w = 0.;
        
        SetCountʷCommand(const SetCountʷCommand&) = delete;
        SetCountʷCommand(SetCountʷCommand&&) = delete;
        SetCountʷCommand& operator=(const SetCountʷCommand&) = delete;
        SetCountʷCommand& operator=(SetCountʷCommand&&) = delete;
    };
}
