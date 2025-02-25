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
    class AddSize² : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize², SizeCommand)
    public:
        AddSize²(const Header&, const Vector2D&);
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddSize²(const AddSize²&, const Header&);
        AddSize²(const Header&);
        ~AddSize²();

    private:
        Vector2D  m_Δ = ZERO;
        
        AddSize²(const AddSize²&) = delete;
        AddSize²(AddSize²&&) = delete;
        AddSize²& operator=(const AddSize²&) = delete;
        AddSize²& operator=(AddSize²&&) = delete;
    };
}
