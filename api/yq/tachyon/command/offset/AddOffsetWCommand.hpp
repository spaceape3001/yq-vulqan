////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/OffsetCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their offset by given amount
    class AddOffsetʷCommand : public OffsetCommand {
        YQ_OBJECT_DECLARE(AddOffsetʷCommand, OffsetCommand)
    public:
        AddOffsetʷCommand(const Header&, double Δw);
    
        static void init_meta();
        
        double  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddOffsetʷCommand(const AddOffsetʷCommand&, const Header&);
        AddOffsetʷCommand(const Header&);
        ~AddOffsetʷCommand();

    private:
        double  m_Δw = 0.0;
        
        AddOffsetʷCommand(const AddOffsetʷCommand&) = delete;
        AddOffsetʷCommand(AddOffsetʷCommand&&) = delete;
        AddOffsetʷCommand& operator=(const AddOffsetʷCommand&);
        AddOffsetʷCommand& operator=(AddOffsetʷCommand&&);
    };
}
