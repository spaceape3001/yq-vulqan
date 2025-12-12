////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/OffsetCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their offset by given amount
    class AddOffsetʸCommand : public OffsetCommand {
        YQ_OBJECT_DECLARE(AddOffsetʸCommand, OffsetCommand)
    public:
        AddOffsetʸCommand(const Header&, double Δy);
    
        static void init_meta();
        
        double  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddOffsetʸCommand(const AddOffsetʸCommand&, const Header&);
        AddOffsetʸCommand(const Header&);
        ~AddOffsetʸCommand();
        
    private:
        double  m_Δy = 0.0;

        AddOffsetʸCommand(const AddOffsetʸCommand&) = delete;
        AddOffsetʸCommand(AddOffsetʸCommand&&) = delete;
        AddOffsetʸCommand& operator=(const AddOffsetʸCommand&) = delete;
        AddOffsetʸCommand& operator=(AddOffsetʸCommand&&) = delete;
    };
}
