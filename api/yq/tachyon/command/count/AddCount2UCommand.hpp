////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddCount²UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCount²UCommand, CountCommand)
    public:
        AddCount²UCommand(const Header&, const Vector2U&);
    
        const Vector2U&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        unsigned  Δx() const { return m_Δ.x; }
        unsigned  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddCount²UCommand(const AddCount²UCommand&, const Header&);
        AddCount²UCommand(const Header&);
        ~AddCount²UCommand();

    private:
        Vector2U  m_Δ = ZERO;
        
        AddCount²UCommand(const AddCount²UCommand&) = delete;
        AddCount²UCommand(AddCount²UCommand&&) = delete;
        AddCount²UCommand& operator=(const AddCount²UCommand&) = delete;
        AddCount²UCommand& operator=(AddCount²UCommand&&) = delete;
    };
}
