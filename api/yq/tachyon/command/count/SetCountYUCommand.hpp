////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCountʸCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCountʸCommand, CountCommand)
    public:
        SetCountʸCommand(const Header&, unsigned);
    
        static void init_meta();
        
        unsigned  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCountʸCommand(const Header&);
        SetCountʸCommand(const SetCountʸCommand&, const Header&);
        ~SetCountʸCommand();

    private:
        unsigned   m_y = 0.;
        
        SetCountʸCommand(const SetCountʸCommand&) = delete;
        SetCountʸCommand(SetCountʸCommand&&) = delete;
        SetCountʸCommand& operator=(const SetCountʸCommand&) = delete;
        SetCountʸCommand& operator=(SetCountʸCommand&&) = delete;
    };
}
