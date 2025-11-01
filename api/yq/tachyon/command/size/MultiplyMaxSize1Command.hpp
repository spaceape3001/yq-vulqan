////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMaxSize¹Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize¹Command, SizeCommand)
    public:
        MultiplyMaxSize¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyMaxSize¹Command();
        MultiplyMaxSize¹Command(const MultiplyMaxSize¹Command&, const Header&);
        MultiplyMaxSize¹Command(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyMaxSize¹Command(const MultiplyMaxSize¹Command&) = delete;
        MultiplyMaxSize¹Command(MultiplyMaxSize¹Command&&) = delete;
        MultiplyMaxSize¹Command& operator=(const MultiplyMaxSize¹Command&) = delete;
        MultiplyMaxSize¹Command& operator=(MultiplyMaxSize¹Command&&) = delete;
    };
}
