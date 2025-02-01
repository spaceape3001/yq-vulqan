////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyPosition¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition¹, SpatialCommand)
    public:
        MultiplyPosition¹(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyPosition¹();
        MultiplyPosition¹(const MultiplyPosition¹&, const Header&);
        MultiplyPosition¹(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyPosition¹(const MultiplyPosition¹&) = delete;
        MultiplyPosition¹(MultiplyPosition¹&&) = delete;
        MultiplyPosition¹& operator=(const MultiplyPosition¹&) = delete;
        MultiplyPosition¹& operator=(MultiplyPosition¹&&) = delete;
    };
}
