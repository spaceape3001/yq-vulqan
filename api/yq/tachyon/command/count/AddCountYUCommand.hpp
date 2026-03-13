////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddCountʸCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCountʸCommand, CountCommand)
    public:
        AddCountʸCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCountʸCommand(const AddCountʸCommand&, const Header&);
        AddCountʸCommand(const Header&);
        ~AddCountʸCommand();

    private:
        unsigned  m_Δy = 0.0;
        
        AddCountʸCommand(const AddCountʸCommand&) = delete;
        AddCountʸCommand(AddCountʸCommand&&) = delete;
        AddCountʸCommand& operator=(const AddCountʸCommand&) = delete;
        AddCountʸCommand& operator=(AddCountʸCommand&&) = delete;
    };
}
