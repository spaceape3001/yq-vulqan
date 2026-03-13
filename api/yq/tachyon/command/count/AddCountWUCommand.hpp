////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddCountʷCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCountʷCommand, CountCommand)
    public:
        AddCountʷCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCountʷCommand(const AddCountʷCommand&, const Header&);
        AddCountʷCommand(const Header&);
        ~AddCountʷCommand();

    private:
        unsigned  m_Δw = 0.0;
        
        AddCountʷCommand(const AddCountʷCommand&) = delete;
        AddCountʷCommand(AddCountʷCommand&&) = delete;
        AddCountʷCommand& operator=(const AddCountʷCommand&) = delete;
        AddCountʷCommand& operator=(AddCountʷCommand&&) = delete;
    };
}
