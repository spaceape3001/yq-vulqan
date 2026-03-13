////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddCountˣUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCountˣUCommand, CountCommand)
    public:
        AddCountˣUCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCountˣUCommand(const AddCountˣUCommand&, const Header&);
        AddCountˣUCommand(const Header&);
        ~AddCountˣUCommand();

    private:
        unsigned  m_Δx = 0.0;
        
        AddCountˣUCommand(const AddCountˣUCommand&) = delete;
        AddCountˣUCommand(AddCountˣUCommand&&) = delete;
        AddCountˣUCommand& operator=(const AddCountˣUCommand&) = delete;
        AddCountˣUCommand& operator=(AddCountˣUCommand&&) = delete;
    };
}
