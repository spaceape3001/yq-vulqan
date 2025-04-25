////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMaxSize¹ : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize¹, SizeCommand)
    public:
        MultiplyMaxSize¹(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyMaxSize¹();
        MultiplyMaxSize¹(const MultiplyMaxSize¹&, const Header&);
        MultiplyMaxSize¹(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyMaxSize¹(const MultiplyMaxSize¹&) = delete;
        MultiplyMaxSize¹(MultiplyMaxSize¹&&) = delete;
        MultiplyMaxSize¹& operator=(const MultiplyMaxSize¹&) = delete;
        MultiplyMaxSize¹& operator=(MultiplyMaxSize¹&&) = delete;
    };
}
