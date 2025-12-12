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
    class AddCount²Command : public CountCommand {
        YQ_OBJECT_DECLARE(AddCount²Command, CountCommand)
    public:
        AddCount²Command(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        unsigned  Δx() const { return m_Δ.x; }
        unsigned  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddCount²Command(const AddCount²Command&, const Header&);
        AddCount²Command(const Header&);
        ~AddCount²Command();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddCount²Command(const AddCount²Command&) = delete;
        AddCount²Command(AddCount²Command&&) = delete;
        AddCount²Command& operator=(const AddCount²Command&) = delete;
        AddCount²Command& operator=(AddCount²Command&&) = delete;
    };
}
