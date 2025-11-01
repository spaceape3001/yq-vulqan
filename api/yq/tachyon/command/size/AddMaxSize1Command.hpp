////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMaxSize¹Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize¹Command, SizeCommand)
    public:
        AddMaxSize¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddMaxSize¹Command();
        AddMaxSize¹Command(const AddMaxSize¹Command&, const Header&);
        AddMaxSize¹Command(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddMaxSize¹Command(const AddMaxSize¹Command&) = delete;
        AddMaxSize¹Command(AddMaxSize¹Command&&) = delete;
        AddMaxSize¹Command& operator=(const AddMaxSize¹Command&) = delete;
        AddMaxSize¹Command& operator=(AddMaxSize¹Command&&) = delete;
    };
}
