////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize² : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize², SizeCommand)
    public:
        AddMinSize²(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddMinSize²(const AddMinSize²&, const Header&);
        AddMinSize²(const Header&);
        ~AddMinSize²();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddMinSize²(const AddMinSize²&) = delete;
        AddMinSize²(AddMinSize²&&) = delete;
        AddMinSize²& operator=(const AddMinSize²&) = delete;
        AddMinSize²& operator=(AddMinSize²&&) = delete;
    };
}
