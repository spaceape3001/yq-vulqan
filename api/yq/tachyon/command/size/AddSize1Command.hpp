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
    class AddSize¹Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize¹Command, SizeCommand)
    public:
        AddSize¹Command(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddSize¹Command();
        AddSize¹Command(const AddSize¹Command&, const Header&);
        AddSize¹Command(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddSize¹Command(const AddSize¹Command&) = delete;
        AddSize¹Command(AddSize¹Command&&) = delete;
        AddSize¹Command& operator=(const AddSize¹Command&) = delete;
        AddSize¹Command& operator=(AddSize¹Command&&) = delete;
    };
}
