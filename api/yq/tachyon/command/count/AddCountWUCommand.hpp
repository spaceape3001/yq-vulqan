////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddCountʷUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCountʷUCommand, CountCommand)
    public:
        AddCountʷUCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCountʷUCommand(const AddCountʷUCommand&, const Header&);
        AddCountʷUCommand(const Header&);
        ~AddCountʷUCommand();

    private:
        unsigned  m_Δw = 0.0;
        
        AddCountʷUCommand(const AddCountʷUCommand&) = delete;
        AddCountʷUCommand(AddCountʷUCommand&&) = delete;
        AddCountʷUCommand& operator=(const AddCountʷUCommand&) = delete;
        AddCountʷUCommand& operator=(AddCountʷUCommand&&) = delete;
    };
}
