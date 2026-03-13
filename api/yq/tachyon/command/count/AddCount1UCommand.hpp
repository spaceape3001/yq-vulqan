////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddCount¹UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCount¹UCommand, CountCommand)
    public:
        AddCount¹UCommand(const Header&, const Vector1U&);
    
        const Vector1U&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        unsigned  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddCount¹UCommand();
        AddCount¹UCommand(const AddCount¹UCommand&, const Header&);
        AddCount¹UCommand(const Header&);

    private:
        Vector1U  m_Δ = ZERO;
        
        AddCount¹UCommand(const AddCount¹UCommand&) = delete;
        AddCount¹UCommand(AddCount¹UCommand&&) = delete;
        AddCount¹UCommand& operator=(const AddCount¹UCommand&) = delete;
        AddCount¹UCommand& operator=(AddCount¹UCommand&&) = delete;
    };
}
