////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCountʷUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCountʷUCommand, CountCommand)
    public:
        SetCountʷUCommand(const Header&, unsigned);
    
        static void init_meta();
        
        unsigned  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCountʷUCommand(const Header&);
        SetCountʷUCommand(const SetCountʷUCommand&, const Header&);
        ~SetCountʷUCommand();

    private:
        unsigned   m_w = 0.;
        
        SetCountʷUCommand(const SetCountʷUCommand&) = delete;
        SetCountʷUCommand(SetCountʷUCommand&&) = delete;
        SetCountʷUCommand& operator=(const SetCountʷUCommand&) = delete;
        SetCountʷUCommand& operator=(SetCountʷUCommand&&) = delete;
    };
}
