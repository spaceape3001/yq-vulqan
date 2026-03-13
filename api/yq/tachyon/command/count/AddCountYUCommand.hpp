////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddCountʸUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCountʸUCommand, CountCommand)
    public:
        AddCountʸUCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCountʸUCommand(const AddCountʸUCommand&, const Header&);
        AddCountʸUCommand(const Header&);
        ~AddCountʸUCommand();

    private:
        unsigned  m_Δy = 0.0;
        
        AddCountʸUCommand(const AddCountʸUCommand&) = delete;
        AddCountʸUCommand(AddCountʸUCommand&&) = delete;
        AddCountʸUCommand& operator=(const AddCountʸUCommand&) = delete;
        AddCountʸUCommand& operator=(AddCountʸUCommand&&) = delete;
    };
}
