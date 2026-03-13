////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCountʸUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCountʸUCommand, CountCommand)
    public:
        SetCountʸUCommand(const Header&, unsigned);
    
        static void init_meta();
        
        unsigned  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCountʸUCommand(const Header&);
        SetCountʸUCommand(const SetCountʸUCommand&, const Header&);
        ~SetCountʸUCommand();

    private:
        unsigned   m_y = 0.;
        
        SetCountʸUCommand(const SetCountʸUCommand&) = delete;
        SetCountʸUCommand(SetCountʸUCommand&&) = delete;
        SetCountʸUCommand& operator=(const SetCountʸUCommand&) = delete;
        SetCountʸUCommand& operator=(SetCountʸUCommand&&) = delete;
    };
}
